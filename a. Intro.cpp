#include <iostream>
#include <vector>
using namespace std;

//int sum(int* arr, int size) {
int sum(const int* const arr, const int size) { // const�� �ٷ� ������ ������ ��ȣ�� ����� ����� (const int* const arr // *(arr�迭�� ù ��° ��)�� ���ȭ, arr�� ���ȭ)
	int sum = 0;
	//arr[0] == *arr; // �迭�� ù��° ��
	//*arr = 10; // �迭�� ù ��° ���� ����
	//arr += 10; // �Ҵ�� �迭�� �ƴ� �ٸ� �迭�� ����ϰ� �ȴ�

	//arr++; // �ּҰ� �ٲ�
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		//arr++ // error
		//size++; // error
		cout << "sum = " << sum << endl;
	}
	return sum;
}

//solid ����
//1. Single Responsibility(���� å���� ��Ģ) - �ϳ��� Ŭ������ �ϳ��� ���Ҹ� �ϵ���
//2. Open / Closed(���� / ������ ��Ģ) - ���ο� ����� �߰��Ǿ ������ �ڵ尡 �����Ǿ�� �ȵȴ� -> Indirect(����)
//3. Liskov Substitution(�������� ġȯ�� ��Ģ)
//4. Interface Segregation(�������̽� �и� ��Ģ)
//5. Dependency Inversion(������ ���� ��Ģ)

class Cat {
public:
	void cat_speak() {
		cout << "�߿�~" << endl;
	}
};
class Dog {
public:
	void dog_speak() {
		cout << "�۸�~" << endl;
	}
};
class Cow {
public:
	void cow_speak() {
		cout << "����~" << endl;
	}
};
class Zoo {
private:
	Cat cat;
	Dog dog;
	Cow cow;
public:
	void speak() {
		dog.dog_speak();
		cat.cat_speak();
		cow.cow_speak();
	}
};

class Animal {
public:
	virtual void speak() const = 0; // �Լ��� ����� ������ ��� ���� ����
};
class Cat : public Animal{
public:
	virtual void speak() const override {
		cout << "�߿�~" << endl;
	}
};
class Dog : public Animal {
public:
	virtual void speak() const override {
		cout << "�۸�~" << endl;
	}
};
class Cow : public Animal {
public:
	void speak() const override {
		cout << "����~" << endl;
	}
};
class Zoo {
private:
	vector<Animal*> array;

public:
	void addAnimal(Animal* const pAnimal) {
		array.push_back(pAnimal);
	}
	void speak() {
		for (const auto& pAnimal : array) {
			pAnimal->speak();
		}
	}
};

// c style
int add(const int a, const int b) {
	return a + b;
}
int sub(const int a, const int b) {
	return a - b;
}
class Calc {
public:
	virtual int calc(const int a, const int b) = 0;
};
class AddCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a + b;
	}
};
class SubCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a - b;
	}
};
class MulCalc : public Calc {
public:
	virtual int calc(const int a, const int b) override {
		return a * b;
	}
};
// c style
int MyCalc(Calc& obj, const int a, const int b) {
	// ����Ǵ� �� ����. ���ο� ��� �ڿ������� ������ �� ���� >> OCP
	return obj.calc(a, b);
}


bool InitInstance(Zoo* pZoo) { // �����Լ��� �״�� �ΰ�, ������ �ʿ��� �κ��� �̰����� ����
	Cat cat;
	Dog dog;
	Cow cow;
	pZoo->addAnimal(&cat);
	pZoo->addAnimal(&dog);
	pZoo->addAnimal(&cow);
	return true;
}
bool Run(Zoo* pZoo) {
	pZoo->speak();
	return true;
}
bool ExitInstance(Zoo* pZoo) {
	return true;
}

int main(int argc, char** argv) {
	//int size = 10;
	const int size = 10; // �б⸸ �ϴ� ����̹Ƿ� const�� ���������ش� // ������ ������ ���� ������ ���� Ȯ���� �� �ְ� ���ش�
	const int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		//size++; // error
		cout << "sum = " << sum << endl;
	}
	//���� 1. ���� ����(syntax) - �����Ϸ��� ����� / 2. �� ���� - �����ڰ� ������� ���ؼ� ����
	//���� �� read, read/write �� ���� �����Ͽ� read�� �ϴ� ���𹮿��� const Ű���带 �־��ش� 

	Zoo zoo;
	Cat cat;
	Dog dog;
	Cow cow;
	zoo.speak();
	zoo.addAnimal(&dog);
	zoo.addAnimal(&cat);
	zoo.addAnimal(&cow);

	Zoo zoo;
	InitInstance(&zoo);
	Run(&zoo);
	ExitInstance(&zoo);

	int a = 10;
	int b = 20;
	int sum;
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	//������ Ÿ��
	//��Ÿ��
	sum = 10 + 20; // ������ �ڵ� // ������ Ÿ��
	sum = a + b; // ������ �ڵ� // ������ Ÿ��
				 // (atoi)������ �ڵ� // ��Ÿ�� // ������ ������ ��� ���� �ٲ� �� �ִ�
	sum = add(a, b);
	//debug -> �Լ��� ���� ���� : ��Ÿ�� �� ���
	//release -> ����ȭ ���� �ڵ�� ���
	cout << a << " + " << b << " = " << sum << endl;

	// �Ϲ�ȭ / Ư��ȭ
	int* p1 = &a;
	int* p2 = &b;
	int* p;

	// int (*)(const int, const int); // �Լ� ������
	typedef int (*FP_CALC)(const int, const int); // �Լ� ������ ������
	FP_CALC calc; // calc : ����Ʈ ������

	//typedef type ������ : �������� ���ο� �ڷ������� ����
	typedef int (*p)(const int a, const int b);
	//typedef oldtype newtype;
	//(typedef) unsigned int UINT;

	typedef int(*FP_CALC(const int, const int));
	FP_CALC calc;

	unsigned int aaa;
	//UINT bbb;

	int result = 0;
	// c style
	result = add(a, b); // add �Լ� : ������ �� �����Ǵ� �Լ�
	result = sub(a, b);
	// �Լ��� ���ؼ� Ư��ȭ

	calc = add;
	result = calc(a, b); // ���� �߿� ����(�� ���ٿ��� ���ǵǴ� �Լ��� ���� �޶���)
	calc = sub;
	result = calc(a, b);

	// cpp style
	Calc* pCalc = new AddCalc();
	result = pCalc->calc(a, b); // a+b
	delete pCalc;

	pCalc = new SubCalc();
	result = pCalc->calc(a, b); // a-b
	delete pCalc;

	AddCalc addCalc;
	Calc& objA = addCalc;
	result = objA.calc(a, b);

	SubCalc subCalc;
	Calc& objB = subCalc;
	result = objB.calc(a, b);

	// c style
	result = MyCalc(addCalc, a, b); // MyCalc�� �������� �� �Ϲ�ȭ
	result = MyCalc(subCalc, a, b);

	// ���Ӱ� �߰��� �κ�
	MulCalc mulCalc;
	result = MyCalc(mulCalc, a, b);
	// ������ �ڵ带 �������� ����

	vector<Calc*> arr = { &addCalc, &subCalc, &mulCalc };
	// �������ִ� ������ ���� �޶���
	/*for (int i = 0; i < arr.size(); i++) {
		MyCalc(arr[i], a, b);
	}*/
	for (auto& pCalc : arr) {
		MyCalc(*pCalc, a, b); // ��Ÿ�ӿ� ���� ����
	}
	return 0;
}

//������ library ��� + ������ ��� �߰�(main()�� �ۼ�) -> ���� ���α׷� �ۼ�
// pointer -> indirect -> virtual function, ������ ����, ocp
// framework ����

//Handler
//
//int a;
//char ch;
//string name;
//Zoo zoo;
//
////void ������(�Ϲ�ȭ), int ������(Ư��ȭ), char ������(Ư��ȭ)
//&a -> void*, int *
//&ch -> void*, char*
//
//typedef void* HANDLE // void �����͸� handle�� ��
