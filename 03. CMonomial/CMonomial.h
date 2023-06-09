class CMonomial
{
private:
	float Coefficient;
	int Exponent;
public:
	friend istream& operator >> (istream&, CMonomial&);
	friend ostream& operator << (ostream&, CMonomial&);
	CMonomial operator*(const CMonomial&);
	CMonomial operator/(const CMonomial&);
	CMonomial operator*=(const CMonomial&);
	CMonomial operator/=(const CMonomial&);
};

istream& operator >> (istream& is, CMonomial& mn)
{
	cout << "Enter the coefficient:			";
	is >> mn.Coefficient;
	cout << "Enter the exponent:			";
	is >> mn.Exponent;
	return is;
}

CMonomial CMonomial::operator*(const CMonomial& mn)
{
	CMonomial m;
	m.Coefficient = Coefficient * mn.Coefficient;
	m.Exponent = Exponent + mn.Exponent;
	return m;
}

CMonomial CMonomial::operator/(const CMonomial& mn)
{
	CMonomial q;
	q.Coefficient = Coefficient / mn.Coefficient;
	q.Exponent = Exponent - mn.Exponent;
	return q;
}

CMonomial CMonomial::operator*=(const CMonomial& mn)
{
	Coefficient *= mn.Coefficient;
	Exponent += mn.Exponent;
	return *this;
}

CMonomial CMonomial::operator/=(const CMonomial& mn)
{
	Coefficient /= mn.Coefficient;
	Exponent -= mn.Exponent;
	return *this;
}

ostream& operator << (ostream& os, CMonomial& mn)
{
	os << mn.Coefficient << "x^" << mn.Exponent;
	return os;
}