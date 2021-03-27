using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 可视化编程实验1
{
	public class Program
	{
		public static void Main(string[] args)
		{
			int n;
			int m = 1;
			int result = 0;
			try
			{
				Console.WriteLine("请输入数字：");
				n = Convert.ToInt32(checked(Console.ReadLine()));
				for (int i = 1; i <= n; i++)
				{
					checked { m = m * i; }
					checked { result += m; }
					
					Console.WriteLine("结果是" + result);
				}
				
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
				
			}
			Console.ReadLine();
		}
	}
}
