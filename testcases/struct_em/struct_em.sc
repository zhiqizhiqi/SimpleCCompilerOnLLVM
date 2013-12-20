struct ss {
	int a, b;
	int c;
	struct s{
		int sa;
		int sb;
	} d;
};

struct ss S;

int main() {
	read(S.d.sa);
	write(S.d.sa);
	read(S.a);
	write(S.a);
	return 0;
}
