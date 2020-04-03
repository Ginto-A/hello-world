//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {
	}
  	~SuperPrime() {
	}
  	void Setnumber(int n) {//设定number的值 
  		int *p =(int*) &number;
		*p = n;
	}
	bool isSuperPrime() {//判断超级素数 
  	  	split(number, N);
  	  	int a = sum();//各位数和 
	  	int b = multi();//各位数积 
	  	int c = squareSum();//各位数平方和 
	  	if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    	return true; 
  	  	return false;
	}
	int show() {//间接访问number 
		return number;
	}
  private:
  	const int number;
  	int N[5], size;//N存储分割的各位数，size表示位数 
  	bool isPrime(int x) { //判断素数 
  		int i = 2;
		if(x < 2) return false;
		for(i = 2; i < x; i++){
    		if(x % i == 0){
    			return false;
			}
		}
		return true;
	}
	void split(int number,int N[]) {
		int i = 0, x = number;
		for(i = 0; x >= 10; i++){
			N[i] = x % 10;
			x = x / 10;
		}//位是倒序的 
		N[i] = x;
		size = i + 1;// number split into N
	}
	int sum() {
		int Sum = 0;
		int i;
		for(i = 0; i < size; i++)
			Sum += N[i];
		return Sum;
	}
	int multi() {
		int Multi = 1;
		int i;
		for(i = 0; i < size; i++)
			Multi *= N[i];
		return Multi;
	}
	int squareSum() {
		int square = 0;
		int i;
		for(i = 0; i < size; i++)
			square += (N[i] * N[i]);
		return square;
	}
};
class Set {
  public:
  	Set(int from, int to) {//设置判断范围 
  	  size = to - from;
  	  begin = from;
  	  end = to;
	}
  	~Set() {
	}
  	int count() { //超级素数个数 
  	  	int count = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
			set[i].Setnumber(i + begin);//设值 
  	    	if(set[i].isSuperPrime())//判断 
  	      		count += 1;
  		}
	  	return count; 
	}
  	int sum() { //超级素数和 
  	  	int sum = 0;
  	  	int i;
  	  	for (i = 0; i < size; i++) {
  	    	set[i].Setnumber(i + begin);//设值 
			if(set[i].isSuperPrime())//判断 
  	      		sum += set[i].show();//number是private，不能直接访问 
		}
  	    return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;//判断范围 
  	int begin, end;//范围开头与结尾 
};
int main() {
  Set ss(100, 999);
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
