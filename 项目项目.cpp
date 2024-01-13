#include <stdio.h>
#define N 900  //�������ѧ����

struct student {
	int ID;   //ѧ��
	char name[60];   //����
	int gs;   //�����ɼ�
	int dw;  //��ѧ����ɼ�
	int yy;   //Ӣ��ɼ�
	int hx;  //��ѧ�ɼ�
	int jsj;   //������ɼ�
} stu[N], stusort;
int M = 0; //MΪȫ�ֱ��������ڴ�ŵ�ǰѧ������
int choose_num;  //choose_numΪȫ�ֱ���
void welcome();//��ӭ���溯������
void menu();//�˵����溯������
void input_message();   //¼�뺯������
void add_message();   //��Ӻ�������
void del_message();   //ɾ����������
void change_message();   //�޸ĺ�������
int find_message();   //��ѯ��������
void display_message();  //��ʾȫ����������
void ID_order();   //��ѧ������������
void score_order();  //���ܳɼ�����������

int main() { //������
	welcome();  //���û�ӭ����
	do {
		menu();  //���ò˵�
		scanf("%d", &choose_num);
		if (choose_num == 1)
			input_message();  //����¼�뺯��
		else if (choose_num == 2)
			add_message();  //������Ӻ���
		else if (choose_num == 3)
			del_message();  //����ɾ������
		else if (choose_num == 4)
			change_message();  //�����޸ĺ���
		else if (choose_num == 5)
			find_message();  //���ò�ѯ����
		else if (choose_num == 6)
			display_message();  //������ʾȫ������
		else if (choose_num == 7)
			ID_order();  //���ð�ѧ��������
		else if (choose_num == 8)
			score_order();   //���ð��ܳɼ�������
		else if (choose_num == 0)
			break;   //����0���˳�����
		else
			printf("��������ȷ������\n");
	} while (1);
	printf("�˳�����");
	return 0;
}
///////////////////////////////////��ӭ���溯��/////////////////////////////////////////

void welcome() {
	printf("        ********            ********\n");
	printf("    ****************    ****************\n");
	printf(" ******************************************\n");
	printf("********************************************\n");
	printf("****      ��ӭ����ѧ���ɼ�����ϵͳ      ****\n");
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

///////////////////////////////////ѡ��˵�����////////////////////////////////////////

void menu() {
	printf("******************************************\n");
	printf("1.¼��\n");
	printf("2.���\n");
	printf("3.ɾ��\n");
	printf("4.�޸�\n");
	printf("5.��ѯ\n");
	printf("6.��ʾȫ��ѧ����Ϣ\n");
	printf("7.��ѧ������\n");
	printf("8.���ܳɼ�����\n");
	printf("0.�˳�\n");
	printf("******************************************\n");
}

////////////////////////////¼�뺯��///////////////////////////////////////////////
void input_message() {
	int i, flag;
	printf("����Ҫ���뼸λѧ������Ϣ��\n");
	scanf("%d", &M);
	/*���²���Ҫ��ѧ���Լ����*/
	/*Ҫ����������M��ѧ���ĸ�����Ϣ����Ϣ��ǰ��struct student�ṹ�壬Ҫ��ÿ�������б�Ҫ����ʾ*/
	for (i = 0, flag = 0; i < M; i++) {

		if (flag == 0) {
			printf("�������%d��ѧ����ѧ��\n", i + 1);
			flag = 1;
		}
		scanf("%d", &stu[i].ID);

		if (flag == 1) {
			printf("�������%d��ѧ��������\n", i + 1);
			flag = 2;
		}
		scanf("%s", stu[i].name);
		if (flag == 2) {
			printf("�������%d��ѧ���ĸ����ɼ�\n", i + 1);
			flag = 3;
		}
		scanf("%d", &stu[i].gs);
		if (flag == 3) {
			printf("�������%d��ѧ���Ĵ�ѧ����ɼ�\n", i + 1);
			flag = 4;
		}
		scanf("%d", &stu[i].dw);
		if (flag == 4) {
			printf("�������%d��ѧ����Ӣ��ɼ�\n", i + 1);
			flag = 5;
		}
		scanf("%d", &stu[i].yy);
		if (flag == 5) {
			printf("�������%d��ѧ���Ļ�ѧ�ɼ�\n", i + 1);
			flag = 6;
		}
		scanf("%d", &stu[i].hx);
		if (flag == 6) {
			printf("�������%d��ѧ���ļ�����ɼ�\n", i + 1);
			flag = 0;
		}
		scanf("%d", &stu[i].jsj);
	}

}
////////////////////////////��Ӻ���///////////////////////////////////////////////


void add_message() { //�����ӹ��ܣ�ÿ�����һ��ѧ����Ϣ
	printf("��������ӵ���ѧ����Ϣ��\n");

	M++;

	printf("������ѧ��:");
	scanf("%d", &stu[M - 1].ID);

	printf("����������:");
	scanf("%s", &stu[M - 1].name);

	printf("����������ɼ�:");
	scanf("%d", &stu[M - 1].gs);

	printf("�������ѧ����ɼ�:");
	scanf("%d", &stu[M - 1].dw);

	printf("������Ӣ��ɼ�:");
	scanf("%d", &stu[M - 1].yy);

	printf("�����뻯ѧ�ɼ�:");
	scanf("%d", &stu[M - 1].hx);

	printf("�����������ɼ�:");
	scanf("%d", &stu[M - 1].jsj);


}

////////////////////////////ɾ������///////////////////////////////////////////////
void del_message() { //ÿ��ɾ��һ��ѧ����Ϣ
	int n, i;
	n = find_message(); //�ȵ��ò�ѯ�������ҳ���Ҫɾ����ѧ��
	if (n >= 0 && n < M) {
		for (i = n; i < M; i++)
			stu[i] = stu[i + 1];
		M--; //ÿ��ɾ��һ��ѧ����Ϣ������ѧ��������Ҫ��1
		printf("��ͬѧ�����ѳɹ�ɾ��\n");
	} else
		printf("ϵͳ����");

}

////////////////////////////�޸ĺ���///////////////////////////////////////////////
void change_message() { //����޸Ĺ��ܣ�ÿ���޸�һ��ѧ����Ϣ
	/*�ú�������ѧ���Լ����*/

	int i, flag1 = 0, flag = 1, n = 0;
	if (choose_num == 4)
		printf("������Ҫ��ѯ��ͬѧѧ�ţ�");
	scanf("%d", &n);
	for (i = 0; i < M; i++)
		if (stu[i].ID == n) {//����ҵ��˶�Ӧ��i��Ӧ��stuid��n����ô���i�µ�������Ϣ�����ҵ����Ǹ�ͬѧ����Ϣ
			flag1 = 1;
			break;
		}
	if (flag1 == 0) {
		printf("δ�ҵ���ͬѧ\n");
	} else if (flag1) {

		if (flag == 1) {
			printf("�������%d��ѧ��������\n", i + 1);
			flag = 2;
		}
		scanf("%s", stu[i].name);
		if (flag == 2) {
			printf("�������%d��ѧ���ĸ����ɼ�\n", i + 1);
			flag = 3;
		}
		scanf("%d", &stu[i].gs);
		if (flag == 3) {
			printf("�������%d��ѧ���Ĵ�ѧ����ɼ�\n", i + 1);
			flag = 4;
		}
		scanf("%d", &stu[i].dw);
		if (flag == 4) {
			printf("�������%d��ѧ����Ӣ��ɼ�\n", i + 1);
			flag = 5;
		}
		scanf("%d", &stu[i].yy);
		if (flag == 5) {
			printf("�������%d��ѧ���Ļ�ѧ�ɼ�\n", i + 1);
			flag = 6;
		}
		scanf("%d", &stu[i].hx);
		if (flag == 6) {
			printf("�������%d��ѧ���ļ�����ɼ�\n", i + 1);
			flag = 0;
		}
		scanf("%d", &stu[i].jsj);

	}
}



////////////////////////////��ʾȫ������///////////////////////////////////////////////
void display_message() { //��ʾȫ��ѧ����Ϣ
	/*�ú�������ѧ���Լ����*/
	int i, flag;
	printf("ȫ��ѧ������Ϣ����\n");
	for (i = 0, flag = 0; i < M; i++) {

		if (flag == 0) {
			printf("��%d��ѧ����ѧ��:", i + 1);
			flag = 1;
		}
		printf("%d\n", stu[i].ID);
		if (flag == 1) {
			printf("��%d��ѧ��������:", i + 1);
			flag = 2;
		}
		printf("%s\n", stu[i].name);
		if (flag == 2) {
			printf("��%d��ѧ���ĸ����ɼ�:", i + 1);
			flag = 3;
		}
		printf("%d\n", stu[i].gs);
		if (flag == 3) {
			printf("��%d��ѧ���Ĵ�ѧ����ɼ�:", i + 1);
			flag = 4;
		}
		printf("%d\n", stu[i].dw);
		if (flag == 4) {
			printf("��%d��ѧ����Ӣ��ɼ�:", i + 1);
			flag = 5;
		}
		printf("%d\n", stu[i].yy);
		if (flag == 5) {
			printf("��%d��ѧ���Ļ�ѧ�ɼ�:", i + 1);
			flag = 6;
		}
		printf("%d\n", stu[i].hx);
		if (flag == 6) {
			printf("��%d��ѧ���ļ�����ɼ�:", i + 1);
			flag = 0;
		}
		printf("%d\n", stu[i].jsj);
	}
}

////////////////////////////��ѯ����///////////////////////////////////////////////
int find_message() {
	int n, i, flag = 0;
	if (choose_num == 5)
		printf("������Ҫ��ѯ��ͬѧѧ�ţ�");
	scanf("%d", &n);
	for (i = 0; i < M; i++)
		if (stu[i].ID == n) {
			flag = 1;
			break;
		}
	if (flag == 1) {
		printf("��������ѧ����ѧ��Ϊ��%d;\n����Ϊ��%s;\n�����ɼ�Ϊ��%d;\n��ѧ����ɼ�Ϊ��%d;\nӢ��ɼ�Ϊ��%d;\n��ѧ�ɼ�Ϊ��%d;\n������ɼ�Ϊ��%d;\n",
		       stu[i].ID, stu[i].name, stu[i].gs, stu[i].dw, stu[i].yy, stu[i].hx, stu[i].jsj);
		return (i);
	} else if (flag == 0) {
		printf("δ�ҵ���ͬѧ\n");
		return (-1);
	}
}

////////////////////////////��ѧ��������///////////////////////////////////////////////
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

////////////////////////////���ܷ�������///////////////////////////////////////////////
void score_order() { //  ���ֶܷ�ѧ���ɼ��ɸߵ��ͽ�������
	/*�ú�������ѧ���Լ����*/
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
