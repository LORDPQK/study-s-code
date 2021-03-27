using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 可视化编程实验1_2
{
	class Program
	{
		
		static void Main(string[] args)
		{
			int ticket_price;
			int choice;
			int  this_month = DateTime.Now.Month;
			if(this_month<11&&this_month>3)
			{
				ticket_price = 60;
			}
			else
			{
				ticket_price = 40;
			}

			
			while (true)
			{
				Console.WriteLine("欢迎参观故宫！");
				Console.WriteLine("请输入参观者类型");
				Console.WriteLine("【1】1.2米以下游客免费");
				Console.WriteLine("【2】大中小学生每人20元");
				Console.WriteLine("【3】离休人员免票");
				Console.WriteLine("【4】老年人半价优惠");
				Console.WriteLine("【5】其他人员");
				choice = Convert.ToInt32(checked(Console.ReadLine()));
				switch (choice)
				{
					case 1:
						Console.WriteLine("免费！");
						break;
					case 2:
						Console.WriteLine("需支付20元");
						break;
					case 3:
						Console.WriteLine("免费");
						break;
					case 4:
						Console.WriteLine("老年人享受半价优惠，需支付" + ticket_price / 2 + "元");
						break;
					case 5:
						Console.WriteLine("需支付" + ticket_price + "元");
						break;
					default:
						Console.WriteLine("输入错误序号，请重新输入");
						break;

				}
			}

			
			
		
		}
	}
}
