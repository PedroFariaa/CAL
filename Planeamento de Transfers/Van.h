class Van{
public:
	Van(int n_pass_max);
	void setN_Max(int n);
	int getN_Max();

private:
	int n_pass_max;
};

Van::Van(int n_pass_max){
	this->n_pass_max=n_pass_max;
}