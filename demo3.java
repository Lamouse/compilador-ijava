class gcd {

	public static int main(String[] args){
		boolean a;
		int[] b;
		boolean[] c;

		a = false;
		b = new int[3];
		c = new boolean[2];

		b[3] = 2;
		c[1] = false;

		System.out.println(b[3]);
		System.out.println(c[1]);
		System.out.println(b.length);
		System.out.println(c.length);
		System.out.println(Integer.parseInt(args[0]));
		System.out.println(Integer.parseInt(args[1]));

		System.out.println(a(false&&true));

		return 1;
	}

	public static boolean a(boolean y){
		return y;
	}
}
