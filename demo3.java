class gcd {
	static int d;
	static int[] e;

	public static int main(String[] args){
		boolean a;
		int[] b;
		boolean[] c;
		int i;

		if((new int[3]).length > 3){
			System.out.println(0);
		}
		else{
			System.out.println(1);
		}
		
		i = (new int[3]).length;

		System.out.println(i);

		System.out.println(args.length);
		
		b = new int[5];
		c = new boolean[15];
		b[0] = 4;
		c[1]=false;

		i = c.length - 1;
		while(i >= 3){
			c[i] = true;
			System.out.println(c[i]);
			i = i -1;
		}
		System.out.println(c.length);

		System.out.println(teste_array(c));

		{
			System.out.println(b[3]);
			System.out.println(c[1]);
			System.out.println(b.length);
			System.out.println(c.length);
			System.out.println(Integer.parseInt(args[0]));
			System.out.println(Integer.parseInt(args[1]));
			System.out.println(a(false&&true));
			System.out.println(true||(false||false));
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

		i=2+(2+5)*5;
		a=false||(true&&(true||false));
		System.out.println(i);
		System.out.println(a);

		return 0;
	}

	public static boolean teste_array(boolean[] a){
		System.out.println(a.length);
		return a[1];
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
