#include "pch.h"

#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "../PAT_HojaDeTrabajo03/Node.h"
#include "../PAT_HojaDeTrabajo03/Ejercicio03.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::string;
using ::std::vector;
using ::std::unordered_map;

namespace HojaDeTrabajo03Tests {

	class E03Tests : public TestWithParam<vector<tuple<int, int>>> {
	protected:
		Ejercicio03* e03;
		vector<tuple<int, int>> param;

		void SetUp() override {
			e03 = new Ejercicio03();
			param = GetParam();
		}

		void TearDown() override {
			delete e03;
			e03 = nullptr;
		}

	public:
		static vector<vector<tuple<int, int>>> ReadParams() {
			vector<vector<tuple<int, int>>> params;

			std::ifstream paramsFile("e03.csv");
			string line;

			while (std::getline(paramsFile, line)) {
				std::stringstream strStream(line);

				vector<tuple<int, int>>pairs;

				string sLeft, sRight;
				int left, right;
				while (std::getline(strStream, sLeft, ',') && std::getline(strStream, sRight, ',')) {
					left = std::stoi(sLeft);
					right = std::stoi(sRight);
					pairs.push_back(tuple<int, int>(left, right));
				}

				params.push_back(pairs);
			}

			return params;
		}
	};

	Node<int>* buildList(vector<tuple<int, int>>& param) {
		vector<Node<int>*> nodes(param.size());

		int size = param.size();

		if (size == 0)
			return nullptr;

		nodes[size - 1] = new Node<int>{ std::get<0>(param[size - 1]) };

		for (int i = size - 2; i >= 0; i--) {
			int value = std::get<0>(param[i]);
			
			nodes[i] = new Node<int>{ value, nodes[i + 1] };
		}

		for (int i = 0; i < size; i++) {
			int randomIndex = std::get<1>(param[i]);
			
			Node<int>* random = ((randomIndex < 0) ? nullptr : nodes[randomIndex]);

			nodes[i]->random = random;
		}

		return nodes[0];
	}

	TEST_P(E03Tests, E03CopiaDeLista) {
		Node<int>* head = buildList(param);

		Node<int>* copy = e03->copyList(head);

		Node<int>* c = copy;
		Node<int>* h = head;

		vector<Node<int>*> copiedNodes(param.size());
		vector<Node<int>*> originalNodes(param.size());

		unordered_map<Node<int>*, Node<int>*> map;

		int i = 0;
		while (c && h) {
			ASSERT_NE(h, c) << "El nodo en la posicion [" << i << "] del resultado pertenece a la lista original, no es una copia.";

			ASSERT_EQ(h->value, c->value) << "El nodo en la posicion [" << i << "] no tiene el mismo valor que en la lista original."
				<< " Se esperaba [" << h->value << "], pero se encontro [" << c->value << "].";

			copiedNodes[i] = c;
			originalNodes[i] = h;

			map[h] = c;

			c = c->next;
			h = h->next;
			++i;
		}

		ASSERT_TRUE(c == nullptr && h == nullptr) << "La cantidad de nodos no es la esperada.";

		Node<int>* originalIt; Node<int>* copiedIt;

		for (int i = 0; i < param.size(); i++) {
			const auto& pair = param[i];

			int value = std::get<0>(pair);
			int randomIndex = std::get<1>(pair);

			originalIt = randomIndex >= 0 ? originalNodes[randomIndex] : nullptr;
			copiedIt = randomIndex >= 0 ? copiedNodes[randomIndex] : nullptr;

			if (originalIt && copiedIt) {
				ASSERT_NE(originalIt, copiedIt)
					<< "El nodo random en la posicion [" << i << "] del resultado pertenece a la lista original, no es una copia.";

				ASSERT_EQ(map[originalIt], copiedIt)
					<< "El nodo random en la posicion [" << i << "] del resultado no pertenece a la lista copiada.";
			}
			else {
				ASSERT_TRUE(originalIt == nullptr && copiedIt == nullptr)
					<< "El nodo random en la posicion [" << i << "] del resultado no apunta a una direccion de memoria equivalente."
					<< "Se esperaba que apuntara a " << (copiedIt ? "[new Node]" : "[nullptr]")
					<< ", pero apunta a " << (copiedIt ? "[new Node]" : "[nullptr]");
			}

			if (originalIt && copiedIt) {
				ASSERT_EQ(originalIt->value, copiedIt->value)
					<< "El nodo random en la posicion [" << i << "] del resultado no tiene el mismo valor que en la lista original."
					<< " Se esperaba [" << originalIt->value << "], pero se encontro [" << copiedIt->value << "].";
			}
		}
	}

	INSTANTIATE_TEST_CASE_P(E03CopiaDeLista, E03Tests, ValuesIn(E03Tests::ReadParams()));
}