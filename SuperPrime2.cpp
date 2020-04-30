//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2到number-1的因子
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
  	  //集合的构造什么？ 
  	  prime_set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //销毁对象 
		delete prime_set[i]; 
	  delete[] prime_set;
	}

	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  prime_set[index] = p;
	  index += 1;
	  return true;//添加数 
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!prime_set[i]->isPrime())
	      return false;
	  return true;//判断是否所有数都是素数 
	} 
  private:
  	Prime **prime_set;
	int size, index;//size是大小，index是下标 
};
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //为什么必须有？ 
  	}
  	SuperPrime(int n):Prime(n)/*使用了基类中的构造函数*/, pset(3) {
	  // number split into N
	  int temp = n;
	  int sum = 0;
	  int multi = 1;
	  int squaremulti = 0;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	sum += t;  //作业：单个数字为对象？还是和/积/平方和为对象？ 
		multi *= t;
		squaremulti += (t * t);  
	  } 
	  pset.add(sum);
	  pset.add(multi);
	  pset.add(squaremulti);
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
	  if (Prime::isPrime() /*使用了基类中的isPrime()*/&& pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
};

class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {
  	  size = to - from;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  /*
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
  	      */ 
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
