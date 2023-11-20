#include "pch.h"

#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_set>

#include "../PAT_HojaDeTrabajo03/Ejercicio02.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::string;
using ::std::vector;
using ::std::unordered_set;

namespace HojaDeTrabajo03Tests {

	class E02Tests : public TestWithParam < tuple<vector<string>, vector<vector<string>>>> {
	protected:
		Ejercicio02* e02;
		vector<string> param;
		vector<vector<string>> expectedResult;

		void SetUp() override {
			e02 = new Ejercicio02();
			std::tie(param, expectedResult) = GetParam();
		}

		void TearDown() override {
			delete e02;
			e02 = nullptr;
		}

	public:
		static vector<tuple<vector<string>, vector<vector<string>>>> ReadParams() {
			vector<tuple<vector<string>, vector<vector<string>>>> params;

			std::ifstream paramsFile("e02.csv");
			string line1, line2;
			while (std::getline(paramsFile, line1) && std::getline(paramsFile, line2)) {
				std::stringstream line1Stream(line1);
				string str;

				vector<string> p;

				while (std::getline(line1Stream, str, ',')) {
					p.push_back(str);
				}

				std::stringstream line2Stream(line2);

				vector<vector<string>> results;
				while (std::getline(line2Stream, str, '|')) {
					std::stringstream arrayStream(str);

					vector<string> result;
					string s;

					while (std::getline(arrayStream, s, ',')) {
						result.push_back(s);
					}
					
					results.push_back(result);
				}

				params.push_back(tuple<vector<string>, vector<vector<string>>>(p, results));
			}

			return params;
		}
	};

	static bool vectorComparator(const vector<string>& a, const vector<string>& b) {
		if (a.size() < b.size())
			return true;

		if (a.size() > b.size())
			return false;

		int size = a.size();

		for (int i = 0; i < size; i++) {
			if (a[i] < b[i])
				return true;
			
			if (a[i] > b[i])
				return false;
		}

		return false;
	}

	TEST_P(E02Tests, E02Anagramas) {
		vector<vector<string>>* actualResult = e02->groupAnagrams(param);

		ASSERT_TRUE(actualResult != nullptr)
			<< "El resultado es [nullptr]";

		int aSize = actualResult->size();
		int eSize = expectedResult.size();

		EXPECT_EQ(expectedResult.size(), actualResult->size()) << "El resultado no tiene la cantidad de datos esperada."
			<< "Se esperaban [" << eSize << "] datos, pero se encontraron ["
			<< aSize << "] datos.";

		std::sort(actualResult->begin(), actualResult->end(), vectorComparator);
		std::sort(expectedResult.begin(), expectedResult.end(), vectorComparator);

		unordered_set<string>* setOfActualResults;
		unordered_set<string>* setOfExpectedResults;

		for (int i = 0; i < aSize && i < eSize; i++) {
			setOfActualResults = new unordered_set<string>((*actualResult)[i].begin(), (*actualResult)[i].end());
			setOfExpectedResults = new unordered_set<string>(expectedResult[i].begin(), expectedResult[i].end());

			for (const auto& expected : *setOfExpectedResults) {
				ASSERT_TRUE(setOfActualResults->find(expected) != setOfActualResults->end())
					<< "No se encontro [" << expected << "] entre los resultados y era esperado.";
			}

			for (const auto& actual : *setOfActualResults) {
				ASSERT_TRUE(setOfExpectedResults->find(actual) != setOfExpectedResults->end())
					<< "Se encontro [" << actual << "] en los resultados pero no era esperado.";
			}

			delete setOfActualResults;
			delete setOfExpectedResults;
		}
	}

	INSTANTIATE_TEST_CASE_P(E02Anagramas, E02Tests, ValuesIn(E02Tests::ReadParams()));
}