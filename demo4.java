class gcd {
	static int a;

	public static void main(String[] args){
		int i;
		i = 0;
		System.out.println(Integer.parseInt(args[1]));
		System.out.println(args.length);

		while(i < args.length){
			System.out.println(Integer.parseInt(args[i]));
			i = i + 1;
		}

		a = 3;
		System.out.println(a);
		System.out.println(soma(a));
		System.out.println(a);
		
	}

	public static int soma(int x){
		return x + 1;
	}
}
