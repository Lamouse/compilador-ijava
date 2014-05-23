class gcd {
	static int d;
	static int[] e;

	public static int main(String[] args){
		boolean a;
		int[] b;
		boolean[] c;
		int i;

		a = false;
		b = new int[3];
		c = new boolean[2];

		b[3] = 2;
		c[1] = false;

		{
			System.out.println(b[3]);
			System.out.println(c[1]);
			System.out.println(b.length);
			System.out.println(c.length);
			System.out.println(Integer.parseInt(args[0]));
			System.out.println(Integer.parseInt(args[1]));
			System.out.println(a(false&&true));
		}

		i = 10;
		while(i >= -10){
			System.out.println(i);
			if(i > 0){
				i = i - 1;
			}
			else{
				i = i - 2;
			}
		}

		System.out.println(compare(1, 2));
		System.out.println(compare(2, 1+1));
		System.out.println(compare(10, 20-15+5));

		d = 2;
		e = new int[1];
		e[0] = 3;
		System.out.println(e[0]);
		System.out.println(e.length);

		System.out.println(06);
		System.out.println(0xf);
		return d;
	}

	public static boolean a(boolean y){
		return y;
	}

	public static boolean compare(int x, int y){
		boolean a;

		if(x == y)
			a = true;
		else
			a = false;
		return a;
	}
}
