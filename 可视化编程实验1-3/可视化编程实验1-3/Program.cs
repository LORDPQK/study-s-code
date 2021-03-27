using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 可视化编程实验1_3
{
	class A
	{
		public int MyMethod(int a)
		{
			a += 10;
			return a;
		}
	}

	class B :A
	{
		public int MyMethod(int a)
		{
			a += 50;
			return a;
		}
	}


	class Program
	{
		static void Main(string[] args)
		{
			int sum1, sum2;
			A one = new A();
			sum1 = one.MyMethod(10);
			Console.WriteLine(sum1);
			B two = new B();
			sum2 = two.MyMethod(10);
			Console.WriteLine(sum2);
			Console.ReadLine();
		}

		
	}

	
}
