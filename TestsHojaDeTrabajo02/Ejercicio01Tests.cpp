#include "pch.h"

#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>

#include "../PAT_HojaDeTrabajo03/Ejercicio01.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::string;
using ::std::vector;

namespace HojaDeTrabajo03Tests {

	class E01Tests : public TestWithParam < tuple<vector<int>, int>> {
	protected:
		Ejercicio01* e01;
		vector<int> param;
		int expectedResult;

		void SetUp() override {
			e01 = new Ejercicio01();
			std::tie(param, expectedResult) = GetParam();
		}

		void TearDown() override {
			delete e01;
			e01 = nullptr;
		}

	public:
		static vector<tuple<vector<int>, int>> ReadParams() {
			vector<tuple<vector<int>, int>> params;

			std::ifstream paramsFile("e01.csv");
			string line;
			while (std::getline(paramsFile, line)) {
				std::stringstream strStream(line);

				vector<int> nums;
				string p;

				while (std::getline(strStream, p, ',')) {
					nums.push_back(std::stoi(p));
				}

				int e = nums.back();
				nums.pop_back();

				params.push_back(tuple<vector<int>, int>(nums, e));
			}
				
			return params;
		}
	};

	TEST_P(E01Tests, E01Minimo) {
		int* nums = &param[0];
		int n = param.size();

		int actualResult = e01->findMin(nums, n);

		ASSERT_EQ(expectedResult, actualResult) << "El valor [" << actualResult << "] no es el esperado. Se esperaba ["
			<< expectedResult << "].";
	}

	INSTANTIATE_TEST_CASE_P(E01Minimo, E01Tests, ValuesIn(E01Tests::ReadParams()));
}