//��ҵ��ɾ������ļ����࣬ʹ�ü̳з���ʵ����ͬ�Ĺ��ܡ� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	virtual bool isPrime() { 
  	  //2��number-1������ 
  	  std::cout << "Prime's isPrime() call" << " " << this->number << std::endl;
  	  int i;
		for(i = 2; i < number; i++){
			if(number % i == 0) break;
		} 
		if(i != number) return false;
		return true;
	}
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	PrimeSet(int from, int to) {
  	  size = to - from; 
  	  set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  delete[] set;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isPrime())
  	      count += 1;
	  return count; 
	}

	bool add(Prime *p) {
	  if(index == size)  return false;
	  set[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  std::cout << "PrimeSet's isAllPrime() call" << std::endl;
	  for(int i = 0; i < index; i++)
	    if (!set[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  int sum = 0;
	  int multi = 1;
	  int squareSum = 0;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	//pset.add(t);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  	sum += t;
	  	multi *= t;
	  	squareSum += (t * t);
	  } 
	  Sum = new Prime(sum);
	  Multi = new Prime(multi);
	  SquareSum = new Prime(squareSum);
	  pset.add(Sum);
	  pset.add(Multi);
	  pset.add(SquareSum);
	}
  	~SuperPrime() {
  		delete Sum;
  		delete Multi;
  		delete SquareSum;
	}
  	virtual bool isPrime() {   //��/����Ľӿڣ�������˵����� 
  	  std::cout << "SuperPrime's isPrime() call" << std::endl;
	  if (Prime::isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
  	Prime *Sum;
	Prime *Multi;
	Prime *SquareSum; 
};
int main() {
  Prime p(13);
  SuperPrime sp(113);
  PrimeSet set(2);
  set.add(&sp); 
  set.add(&p);
  std::cout << "How Many : " << set.count() << std::endl;
  return 0;
}
