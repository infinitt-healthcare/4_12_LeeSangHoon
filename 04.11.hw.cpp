//A, B�� �Է¹��� ��, A/B(������)�� ���
//0���� �������� ��, ���ڰ� ������ �� ����ó��
//�Լ�ȭ�Ͽ� �����

#include <iostream>
#include <vector>
using namespace std;

class Calc {
public:
	virtual int calc(const int a, const int b) = 0;
};
//class AddCalc : public Calc {
//public:
//	virtual int calc(const int a, const int b) override {
//		return a + b;
//	}
//};
//class SubCalc : public Calc {
//public:
//	virtual int calc(const int a, const int b) override {
//		return a - b;
//	}
//};
//class MulCalc : public Calc {
//public:
//	virtual int calc(const int a, const int b) override {
//		return a * b;
//	}
//};
class DivCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		if (b == 0) {
			cout << "������ ���� 0�� �� �� �����ϴ�. " << endl;
		}
		exit(-1);
		return a / b;
	}
};



//class Calc {
//public:
//	void Divide();
//};
//class Div : public Calc {
//public:
//	int Divide(int& A, int& B) {
//		if (B == 0) {
//			cout << "������ ���� 0�� �� �� �����ϴ�. " << endl;
//		}
//		exit(-1);
//		return A / B;
//	}
//};
//class Calculate {
//private:
//	vector<Calc*> array;
//
//public:
//	void DivCalc(Calc* pCalc) {
//		array.push_back(pCalc);
//	}
//	void Divide() {
//		for (auto& pCalc : array) {
//			pCalc->Divide();
//		}
//	}
//};
//void InitCalc(Calc* pCalc) {
//	Div div;
//	pCalc->Divide();
//}
//void RunCalc(Calc* pCalc) {
//	pCalc->Divide();
//}
//void ExitCalc(Calc* pCalc) {
//}



//void setVar(int &_A, int &_B) {
//	cout << "�Է��Ͻ� ���� " << "A : " << _A << ", B : " << _B << "�Դϴ�." << endl;
//
//	cout << "A �� ? : ";
//	cin >> _A;
//	cout << "B �� ? : ";
//	cin >> _B;
//	
//	cout << "�Է��Ͻ� ���� " << "A : " << _A << ", B : " << _B << "�Դϴ�." << endl;
//}
//void Divide() {
//
//}
//

int main()
{
	cout << "A ������ B ����" << endl;
	//int A;
	//int B;

	int result = 0;
	//int a = 100;
	//int b = 0;

	Calc* pCalc = new DivCalc; // Ŭ���� ��ü ����, ��ü �޸� �Ҵ�
	//result = pCalc->calc(a, b); // ������ �� �Է�
	result = pCalc->calc(100, 0); // ���� �� �Է�
	cout << result;
	delete pCalc;
	cout << "==============================" << endl;
	/*InitCalc(Calc * pCalc);
	RunCalc(Calc * pCalc);
	ExitCalc(Calc * pCalc);*/
	cout << "==============================" << endl;

	//setVar(A, B);
	//Divide();

	return 0;
}