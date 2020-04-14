//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {  //为什么必须有？ 
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //它就是构造对象 
	}
  	~SuperPrime() {
  	  for (int i = 0; i < size; ++i)  //销毁对象 
		delete N[i]; 
	}
  	bool isSuperPrime() {
  	  SuperPrime a(this->sum());   //将普通整数转变为对象 
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
  	  //2到number-1的因子 
  	  return false;
	}
	void split() {   //工厂方法设计模式 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	N[size] = new SuperPrime(n);   //构造对象 
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
  	Set(int from, int to) {//设置判断范围 
  	  size = 0;
	}
  	~Set() {
	}
  	int count() { //超级素数个数 
  	  	int count = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
  	    	if(set[i].isSuperPrime())//判断 
  	      		count += 1;
  		}
	  	return count; 
	}
  	int sum() { //超级素数和 
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
  	int size;//判断范围 
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
