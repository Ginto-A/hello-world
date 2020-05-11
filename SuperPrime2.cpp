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
  	bool isPrime() { 
  	  //2��number-1������ 
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
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0){  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n){
	  // number split into N
	  int temp = n;
	  int SUm = 0;
	  int MUlti = 1;
	  int SQuareSum = 0;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	SUm += t;
		MUlti *= t;
		SQuareSum += (t * t);	
	  } 
	  sum = new Prime(SUm);
	  multi = new Prime(MUlti);
	  squareSum = new Prime(SQuareSum); 
	}
  	~SuperPrime() {
  		delete sum;
  		delete multi;
  		delete squareSum;
	}
  	bool isPrime() {   //��/����Ľӿڣ�������˵����� 
	  if (Prime::isPrime() && sum->isPrime() && multi->isPrime() && squareSum->isPrime())
	    return true; 
  	  return false;
	}
  private:
	Prime *sum; 
	Prime *multi;
	Prime *squareSum;
};
int main() {
  SuperPrime sp(113);
  if (sp.isPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
