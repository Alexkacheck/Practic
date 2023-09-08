
#include <iostream>
#include <string>
class Complex {
public:
	constexpr Complex(const double& real = 0, const double& imag = 0) : real_(real), imag_(imag) { }
	bool conj(const Complex& c)const {
		int a = imag_ < 0 ? -1 : 0;
		int b = c.imag_ < 0 ? -1 : 0;
		return *this == c && a != b;
	}
	void read() {
		std::cout << "a: ";
		std::cin >> real_;
		std::cout << "b: ";
		std::cin >> imag_;
	}
	void display() {
		std::cout << real_ << (imag_ < 0 ? " - " : " + ") << abs(imag_) << 'i';
	}
	std::string toString()const {
		auto real = std::to_string(real_);
		real.erase(real.find_last_not_of("0") + 1);
		real.erase(real.find_last_not_of(".") + 1);
		auto imag = std::to_string(abs(imag_));
		imag.erase(imag.find_last_not_of("0") + 1);
		imag.erase(imag.find_last_not_of(".") + 1);
		return real + (imag_ < 0 ? " - " : " + ") + imag + "i";
	}
private:
	double real_;
	double imag_;
	friend Complex operator+(const Complex& a, const Complex& b) {
		return Complex(a.real_ + b.real_, a.imag_ + b.imag_);
	}
	friend Complex operator-(const Complex& a, const Complex& b) {
		return Complex(a.real_ - b.real_, a.imag_ - b.imag_);
	}
	friend Complex operator*(const Complex& a, const Complex& b) {
		return Complex(a.real_ * b.real_ - a.imag_ * b.imag_, a.real_ * b.imag_ + b.real_ * a.imag_);
	}
	friend Complex operator/(const Complex& a, const Complex& b) {
		auto aa = a.real_ * a.real_;
		auto bb = a.imag_ * a.imag_;
		auto ab = aa + bb;
		if (a.conj(b)) return Complex(a.real_ / ab, -a.imag_ / ab);
		auto cc = b.real_ * b.real_;
		auto dd = b.imag_ * b.imag_;
		auto ac = a.real_ * b.real_;
		auto bd = a.imag_ * b.imag_;
		auto bc = a.imag_ * b.real_;
		auto ad = a.real_ * b.imag_;
		auto cd = cc + dd;
		return Complex((ac + bd) / cd, (bc - ad) / cd);
	}
	friend bool operator==(const Complex& a, const Complex& b) {
		return a.real_ == b.real_ && a.imag_ == b.imag_;
	}
};
int main() {
	Complex x(7, 4);
	x.display();
	std::cout.put('\n');
	Complex y(3, 2);
	y.display();
	std::cout.put('\n');
	auto xy = x + y;
	xy.display();
	std::cout.put('\n');
	auto yx = y + x;
	yx.display();
	std::cout.put('\n');
	puts(xy == yx ? "Equal" : "Not equal");
	auto sub = x - y;
	sub.display();
	std::cout.put('\n');
	auto div = x / y;
	div.display();
	std::cout.put('\n');
	auto mlt = x * y;
	mlt.display();
	std::cout.put('\n');
	auto x_str = x.toString();
	std::cout << x_str << '\n';
	auto div_str = div.toString();
	std::cout << div_str << '\n';
	system("pause > nul");
}