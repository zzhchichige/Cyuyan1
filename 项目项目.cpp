#include <stdio.h>
#define N 900  //最大输入学生数

struct student {
	int ID;   //学号
	char name[60];   //姓名
	int gs;   //高数成绩
	int dw;  //大学物理成绩
	int yy;   //英语成绩
	int hx;  //化学成绩
	int jsj;   //计算机成绩
} stu[N], stusort;
int M = 0; //M为全局变量，用于存放当前学生人数
int choose_num;  //choose_num为全局变量
void welcome();//欢迎界面函数声明
void menu();//菜单界面函数声明
void input_message();   //录入函数声明
void add_message();   //添加函数声明
void del_message();   //删除函数声明
void change_message();   //修改函数声明
int find_message();   //查询函数声明
void display_message();  //显示全部函数声明
void ID_order();   //按学号排序函数声明
void score_order();  //按总成绩排序函数声明

int main() { //主函数
	welcome();  //调用欢迎界面
	do {
		menu();  //调用菜单
		scanf("%d", &choose_num);
		if (choose_num == 1)
			input_message();  //调用录入函数
		else if (choose_num == 2)
			add_message();  //调用添加函数
		else if (choose_num == 3)
			del_message();  //调用删除函数
		else if (choose_num == 4)
			change_message();  //调用修改函数
		else if (choose_num == 5)
			find_message();  //调用查询函数
		else if (choose_num == 6)
			display_message();  //调用显示全部函数
		else if (choose_num == 7)
			ID_order();  //调用按学号排序函数
		else if (choose_num == 8)
			score_order();   //调用按总成绩排序函数
		else if (choose_num == 0)
			break;   //输入0，退出程序
		else
			printf("请输入正确的数字\n");
	} while (1);
	printf("退出程序");
	return 0;
}
///////////////////////////////////欢迎界面函数/////////////////////////////////////////

void welcome() {
	printf("        ********            ********\n");
	printf("    ****************    ****************\n");
	printf(" ******************************************\n");
	printf("********************************************\n");
	printf("****      欢迎进入学生成绩管理系统      ****\n");
	printf("  ****************************************\n");
	printf("    ************************************\n");
	printf("      ********************************\n");
	printf("        ****************************\n");
	printf("          ************************\n");
	printf("            ********************\n");
	printf("              ****************\n");
	printf("                ************\n");
	printf("                  ********\n");
	printf("                    ****\n");
}

///////////////////////////////////选择菜单函数////////////////////////////////////////

void menu() {
	printf("******************************************\n");
	printf("1.录入\n");
	printf("2.添加\n");
	printf("3.删除\n");
	printf("4.修改\n");
	printf("5.查询\n");
	printf("6.显示全部学生信息\n");
	printf("7.按学号排序\n");
	printf("8.按总成绩排序\n");
	printf("0.退出\n");
	printf("******************************************\n");
}

////////////////////////////录入函数///////////////////////////////////////////////
void input_message() {
	int i, flag;
	printf("请问要输入几位学生的信息？\n");
	scanf("%d", &M);
	/*以下部分要求学生自己完成*/
	/*要求依次输入M个学生的各项信息，信息见前面struct student结构体，要求每次输入有必要的提示*/
	for (i = 0, flag = 0; i < M; i++) {

		if (flag == 0) {
			printf("请输入第%d个学生的学号\n", i + 1);
			flag = 1;
		}
		scanf("%d", &stu[i].ID);

		if (flag == 1) {
			printf("请输入第%d个学生的姓名\n", i + 1);
			flag = 2;
		}
		scanf("%s", stu[i].name);
		if (flag == 2) {
			printf("请输入第%d个学生的高数成绩\n", i + 1);
			flag = 3;
		}
		scanf("%d", &stu[i].gs);
		if (flag == 3) {
			printf("请输入第%d个学生的大学物理成绩\n", i + 1);
			flag = 4;
		}
		scanf("%d", &stu[i].dw);
		if (flag == 4) {
			printf("请输入第%d个学生的英语成绩\n", i + 1);
			flag = 5;
		}
		scanf("%d", &stu[i].yy);
		if (flag == 5) {
			printf("请输入第%d个学生的化学成绩\n", i + 1);
			flag = 6;
		}
		scanf("%d", &stu[i].hx);
		if (flag == 6) {
			printf("请输入第%d个学生的计算机成绩\n", i + 1);
			flag = 0;
		}
		scanf("%d", &stu[i].jsj);
	}

}
////////////////////////////添加函数///////////////////////////////////////////////


void add_message() { //完成添加功能，每次添加一个学生信息
	printf("请输入添加的新学生信息：\n");

	M++;

	printf("请输入学号:");
	scanf("%d", &stu[M - 1].ID);

	printf("请输入姓名:");
	scanf("%s", &stu[M - 1].name);

	printf("请输入高数成绩:");
	scanf("%d", &stu[M - 1].gs);

	printf("请输入大学物理成绩:");
	scanf("%d", &stu[M - 1].dw);

	printf("请输入英语成绩:");
	scanf("%d", &stu[M - 1].yy);

	printf("请输入化学成绩:");
	scanf("%d", &stu[M - 1].hx);

	printf("请输入计算机成绩:");
	scanf("%d", &stu[M - 1].jsj);


}

////////////////////////////删除函数///////////////////////////////////////////////
void del_message() { //每次删除一个学生信息
	int n, i;
	n = find_message(); //先调用查询函数，找出需要删除的学生
	if (n >= 0 && n < M) {
		for (i = n; i < M; i++)
			stu[i] = stu[i + 1];
		M--; //每次删除一个学生信息后，总体学生人数需要减1
		printf("该同学数据已成功删除\n");
	} else
		printf("系统错误");

}

////////////////////////////修改函数///////////////////////////////////////////////
void change_message() { //完成修改功能，每次修改一个学生信息
	/*该函数留给学生自己完成*/

	int i, flag1 = 0, flag = 1, n = 0;
	if (choose_num == 4)
		printf("请输入要查询的同学学号：");
	scanf("%d", &n);
	for (i = 0; i < M; i++)
		if (stu[i].ID == n) {//如果找到了对应的i对应的stuid是n，那么这个i下的所有信息都是找到的那个同学的信息
			flag1 = 1;
			break;
		}
	if (flag1 == 0) {
		printf("未找到该同学\n");
	} else if (flag1) {

		if (flag == 1) {
			printf("请输入第%d个学生的姓名\n", i + 1);
			flag = 2;
		}
		scanf("%s", stu[i].name);
		if (flag == 2) {
			printf("请输入第%d个学生的高数成绩\n", i + 1);
			flag = 3;
		}
		scanf("%d", &stu[i].gs);
		if (flag == 3) {
			printf("请输入第%d个学生的大学物理成绩\n", i + 1);
			flag = 4;
		}
		scanf("%d", &stu[i].dw);
		if (flag == 4) {
			printf("请输入第%d个学生的英语成绩\n", i + 1);
			flag = 5;
		}
		scanf("%d", &stu[i].yy);
		if (flag == 5) {
			printf("请输入第%d个学生的化学成绩\n", i + 1);
			flag = 6;
		}
		scanf("%d", &stu[i].hx);
		if (flag == 6) {
			printf("请输入第%d个学生的计算机成绩\n", i + 1);
			flag = 0;
		}
		scanf("%d", &stu[i].jsj);

	}
}



////////////////////////////显示全部函数///////////////////////////////////////////////
void display_message() { //显示全部学生信息
	/*该函数留给学生自己完成*/
	int i, flag;
	printf("全部学生的信息如下\n");
	for (i = 0, flag = 0; i < M; i++) {

		if (flag == 0) {
			printf("第%d个学生的学号:", i + 1);
			flag = 1;
		}
		printf("%d\n", stu[i].ID);
		if (flag == 1) {
			printf("第%d个学生的姓名:", i + 1);
			flag = 2;
		}
		printf("%s\n", stu[i].name);
		if (flag == 2) {
			printf("第%d个学生的高数成绩:", i + 1);
			flag = 3;
		}
		printf("%d\n", stu[i].gs);
		if (flag == 3) {
			printf("第%d个学生的大学物理成绩:", i + 1);
			flag = 4;
		}
		printf("%d\n", stu[i].dw);
		if (flag == 4) {
			printf("第%d个学生的英语成绩:", i + 1);
			flag = 5;
		}
		printf("%d\n", stu[i].yy);
		if (flag == 5) {
			printf("第%d个学生的化学成绩:", i + 1);
			flag = 6;
		}
		printf("%d\n", stu[i].hx);
		if (flag == 6) {
			printf("第%d个学生的计算机成绩:", i + 1);
			flag = 0;
		}
		printf("%d\n", stu[i].jsj);
	}
}

////////////////////////////查询函数///////////////////////////////////////////////
int find_message() {
	int n, i, flag = 0;
	if (choose_num == 5)
		printf("请输入要查询的同学学号：");
	scanf("%d", &n);
	for (i = 0; i < M; i++)
		if (stu[i].ID == n) {
			flag = 1;
			break;
		}
	if (flag == 1) {
		printf("您搜索的学生的学号为：%d;\n姓名为：%s;\n高数成绩为：%d;\n大学物理成绩为：%d;\n英语成绩为：%d;\n化学成绩为：%d;\n计算机成绩为：%d;\n",
		       stu[i].ID, stu[i].name, stu[i].gs, stu[i].dw, stu[i].yy, stu[i].hx, stu[i].jsj);
		return (i);
	} else if (flag == 0) {
		printf("未找到该同学\n");
		return (-1);
	}
}

////////////////////////////按学号排序函数///////////////////////////////////////////////
void ID_order() {
	int i, j;
	for (i = 0; i < M - 1; i++)
		for (j = 0; j < M - 1 - i; j++) {
			if (stu[j].ID > stu[j + 1].ID) {
				stusort = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stusort;
			}
		}
	display_message();
}

////////////////////////////按总分排序函数///////////////////////////////////////////////
void score_order() { //  按总分对学生成绩由高到低进行排序
	/*该函数留给学生自己完成*/
	int Sum(int);
	int i, j;
	for (i = 0; i < M - 1; i++) {
		for (j = i; j < M; j++) {
			if (Sum(i) < Sum(j)) {
				stusort = stu[i];
				stu[i] = stu[j];
				stu[j] = stusort;
			}
		}

	}
	display_message();
}

int Sum(int i) {
	return (stu[i].dw + stu[i].gs + stu[i].hx + stu[i].jsj + stu[i].yy);
}
