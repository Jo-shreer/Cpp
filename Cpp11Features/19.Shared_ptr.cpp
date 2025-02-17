class Smartptr
{
	private:
	int *p;
	int ref_count;

	public:
	Smartptr(int *ptr = NULL)
	{
		p = ptr;
	}

	Smartptr(const Smartptr & other)
	{
		p = other.p;
		ref_count++;
	}

	int& opretor*()
	{
		return *p;
	}

	~Smartptr()
	{
		if(ref_count == 0)
		{
			ref_count--;
			delete p;
		}
	}
};

int main()
{
	Smartptr sp(new int(40);
	return 0;
}
