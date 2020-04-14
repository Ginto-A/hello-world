//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {  //Ϊʲô�����У� 
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
  	  for (int i = 0; i < size; ++i)  //���ٶ��� 
		delete N[i]; 
	}
  	bool isSuperPrime() {
  	  SuperPrime a(this->sum());   //����ͨ����ת��Ϊ���� 
	  SuperPrime b(multi());
	  SuperPrime c(squareSum());
	  if (isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	SuperPrime *N[100];
  	
	int size;
  	bool isPrime() { 
  	  //2��number-1������ 
  	  return false;
	}
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	N[size] = new SuperPrime(n);   //������� 
	  	size += 1;
	  } 
	}
	SuperPrime sum() {
		int sum = 0;
		for(int i = 0; i < size; i++){
			sum += N[i]->number;
		}
		SuperPrime Sum(sum);
		return Sum; 
	}
	SuperPrime multi() {
		int multi = 0;
		for(int i = 0; i < size; i++){
			multi *= N[i]->number;
		}
		SuperPrime Multi(multi);
		return Multi;
	}
	SuperPrime squareSum() {
		int squareSum = 0;
		for(int i = 0; i < size; i++){
			squareSum += (N[i]->number * N[i]->number);
		}
		SuperPrime SquareSum(squareSum);
		return SquareSum;
	}
};
class Set {
  public:
  	Set(int from, int to) {//�����жϷ�Χ 
  	  size = 0;
	}
  	~Set() {
	}
  	int count() { //������������ 
  	  	int count = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
  	    	if(set[i].isSuperPrime())//�ж� 
  	      		count += 1;
  		}
	  	return count; 
	}
  	int sum() { //���������� 
  	  	int sum = 0;
  	  	/*int i;
  	  	for(i = 0; i < size; i++)
			if(set[i].isSuperPrime())
				count++;
				*/
  	    return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;//�жϷ�Χ 
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
