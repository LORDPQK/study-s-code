using System;

public class text
{
	public static void Main()
	{
		int n,result;
		int m = 1;
		try
		{
			Console.Writeline("请输入数字:");
			n = Convert.ToInt32(checked(Console.ReadLine()));
			for(int i=1;i<=n;i++)
			{
				m = m * i;
				result += m;
			}

			Console.WriteLine("结果是：" + result);

		}
		catch(OverflowException e)
		{
			Console.WriteLine(e);
		}
		

	}
}