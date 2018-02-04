#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "String.h"

static int tests_status = 0;

#define TEST(FUNC, ID) if (FUNC() != 0) \
	{ printf("Test %d -- FAILED --\n", ID); tests_status = 1; } \
	else { printf("Test %d OK\n", ID); }

#define INIT() String str1, str2, str3; \
	StringInit(&str1, "Hello, world!"); \
	StringInit(&str2, ""); \
	StringInit(&str3, NULL);

#define DESTROY() StringDestroy(&str1); \
	StringDestroy(&str2); \
	StringDestroy(&str3);

int Test00()
{
	INIT()

	if (strcmp(str1.str, "Hello, world!") != 0) {
		return 1;
	}
	if (strcmp(str2.str, "") != 0) {
		return 1;
	}
	if (str3.str != NULL) {
		return 1;
	}

	DESTROY()

	// Should work
	StringDestroy(NULL);

	if (str1.str != NULL) {
		return 1;
	}
	if (str2.str != NULL) {
		return 1;
	}
	if (str3.str != NULL) {
		return 1;
	}
	return 0;
}

int Test01()
{
	String str1;
	String str2;
	String str3;
	String str4;
	String str5;
	String str6;

	StringInit(&str1, "Hello, world!");
	StringInit(&str2, "Hello, world!");
	StringInit(&str3, "Hello, world!");
	StringInit(&str4, "Hello, world!");
	StringInit(&str5, "Hello, world!");
	StringInit(&str6, "Hello, world!");

	str1.assign_c(&str1, "Goodbye, world...");
	str2.assign_c(&str2, "");
	str3.assign_c(&str3, NULL);

	if (strcmp(str1.str, "Goodbye, world...") != 0) {
		return 1;
	}
	if (strcmp(str2.str, "") != 0) {
		return 1;
	}
	if (str3.str != NULL) {
		return 1;
	}

	str4.assign_s(&str4, &str1);
	str5.assign_s(&str5, &str2);
	str6.assign_s(&str6, &str3);

	if (strcmp(str4.str, "Goodbye, world...") != 0) {
		return 1;
	}
	if (strcmp(str5.str, "") != 0) {
		return 1;
	}
	if (str6.str != NULL) {
		return 1;
	}
	return 0;
}

int Test02()
{
	{
		String str1;
		String str2;
		String str3;

		StringInit(&str1, "Hello");
		StringInit(&str2, "");
		StringInit(&str3, NULL);

		str1.append_c(&str1, ", world!");
		str2.append_c(&str2, "Hello, world!");
		str2.append_c(&str2, "");
		str3.append_c(&str3, "Hello, world!");
		str3.append_c(&str3, NULL);

		if (strcmp(str1.str, "Hello, world!") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "Hello, world!") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello, world!") != 0) {
			return 1;
		}

		DESTROY()
	}

	{
		String str1;
		String str2;
		String str3;

		String str4;
		String str5;
		String str6;
		String str7;

		StringInit(&str4, ", world!");
		StringInit(&str5, "Hello, world!");
		StringInit(&str6, "");
		StringInit(&str7, NULL);

		StringInit(&str1, "Hello");
		StringInit(&str2, "");
		StringInit(&str3, NULL);

		str1.append_s(&str1, &str4);
		str2.append_s(&str2, &str5);
		str2.append_s(&str2, &str6);
		str3.append_s(&str3, &str5);
		str3.append_s(&str3, &str7);

		if (strcmp(str1.str, "Hello, world!") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "Hello, world!") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello, world!") != 0) {
			return 1;
		}

		DESTROY()
	}

	return 0;
}

int Test03()
{
	INIT()

	char pos[14];

	char check[14] = {
		-1, 'H', ',', '!', -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1
	};

	pos[0] = str1.at(&str1, -21);
	pos[1] = str1.at(&str1, 0);
	pos[2] = str1.at(&str1, 5);
	pos[3] = str1.at(&str1, 12);
	pos[4] = str1.at(&str1, 13);
	pos[5] = str1.at(&str1, 42);
	pos[6] = str2.at(&str2, -84);
	pos[7] = str2.at(&str2, -1);
	pos[8] = str2.at(&str2, 0);
	pos[9] = str2.at(&str2, 1);
	pos[10] = str2.at(&str2, 84);
	pos[11] = str3.at(&str3, 12);
	pos[12] = str3.at(&str3, 0);
	pos[13] = str3.at(&str3, -42);
	for (int i = 0; i < 14; ++i) {
		if (pos[i] != check[i]) {
			return 1;
		}
	}

	DESTROY()
	return 0;
}

int Test04()
{
	INIT()

	str1.clear(&str1);
	str2.clear(&str2);
	str3.clear(&str3);

	if (strlen(str1.str) != 0) {
		return 1;
	}
	if (strlen(str2.str) != 0) {
		return 1;
	}
	if (strlen(str3.str) != 0) {
		return 1;
	}

	DESTROY()
	return 0;
}

int Test05()
{
	INIT()

	if (str1.size(&str1) != 13) {
		return 1;
	}
	if (str2.size(&str2) != 0) {
		return 1;
	}
	if (str3.size(&str3) != -1) {
		return 1;
	}

	DESTROY()
	return 0;
}

int Test06()
{
	String str[10];

	StringInit(&(str[0]), "Hello, world!");
	StringInit(&(str[1]), "Hallo, world!");
	StringInit(&(str[2]), "");
	StringInit(&(str[3]), "Give your meat a good ol' rub");
	StringInit(&(str[4]), "Give your meat a good ol' rub!");
	StringInit(&(str[5]), "A");
	StringInit(&(str[6]), "AA");
	StringInit(&(str[7]), "Are you OK ?");
	StringInit(&(str[8]), "Are you ok ?");
	StringInit(&(str[9]), "ello, world!");

	#define CMP(A, B) \
		if ((str[A].compare_s(&(str[A]), &(str[B]))) != \
		(strcmp(str[A].str, str[B].str)) || \
		(str[A].compare_c(&(str[A]), str[B].str)) != \
		(strcmp(str[A].str, str[B].str))) \
		{ return 1; }

	CMP(0, 0)
	CMP(0, 1)
	CMP(1, 0)
	CMP(3, 4)
	CMP(4, 3)
	CMP(2, 0)
	CMP(2, 2)
	CMP(5, 6)
	CMP(6, 5)
	CMP(8, 7)
	CMP(0, 0)
	CMP(4, 2)
	CMP(7, 9)

	for (int i = 0; i < 1000; ++i) {
		int a = random() % 10;
		int b = random() % 10;
		CMP(a, b)
	}

	#undef CMP

	return 0;
}

int Test07()
{
	INIT()

	char *a = calloc(14, sizeof(char));
	char *b = calloc(8, sizeof(char));
	char *c = calloc(1, sizeof(char));
	char *d = calloc(1, sizeof(char));
	char *e = calloc(1, sizeof(char));
	char *f = calloc(1, sizeof(char));
	char *g = calloc(1, sizeof(char));
	char *h = calloc(1, sizeof(char));

	str1.copy(&str1, a, 19, 0);
	str1.copy(&str1, b, 7, 5);
	str1.copy(&str1, c, 1, 13);
	str1.copy(&str1, d, 42, 42);
	str2.copy(&str2, e, 0, 0);
	str2.copy(&str2, f, 5, 5);
	str3.copy(&str3, g, 0, 0);
	str3.copy(&str3, h, 5, 8);

	if (strcmp(a, "Hello, world!") != 0) {
		printf("coco\n");
		return 1;
	}
	if (strcmp(b, ", world") != 0) {
		return 1;
	}
	if (strcmp(c, "") != 0) {
		return 1;
	}
	if (strcmp(d, "") != 0) {
		return 1;
	}
	if (strcmp(e, "") != 0) {
		return 1;
	}
	if (strcmp(f, "") != 0) {
		return 1;
	}
	if (strcmp(g, "") != 0) {
		return 1;
	}
	if (strcmp(h, "") != 0) {
		return 1;
	}

	DESTROY()
	return 0;
}

int Test08()
{
	INIT()

	if (strcmp(str1.c_str(&str1), "Hello, world!") != 0) {
		return 1;
	}
	if (strcmp(str2.c_str(&str2), "") != 0) {
		return 1;
	}
	if (str3.c_str(&str3) != NULL) {
		return 1;
	}

	DESTROY()
	return 0;
}

int Test09()
{
	INIT()

	if (str1.empty(&str1) != -1) {
		return 1;
	}
	if (str2.empty(&str3) != 1) {
		return 1;
	}
	if (str3.empty(&str3) != 1) {
		return 1;
	}

	DESTROY()
	return 0;
}

int Test10()
{
	String str_1;
	String str_2;

	StringInit(&str_1, "Alain soral vs David conversano!");
	StringInit(&str_2, "~1933");

	if (str_1.find_c(&str_1, "Alain", 0) != 0) {
		return 1;
	}
	if (str_1.find_c(&str_1, "soral", 2) != 6) {
		return 1;
	}
	if (str_1.find_c(&str_1, "o!", 20) != 30) {
		return 1;
	}
	if (str_1.find_c(&str_1, "Alain", 20) != -1) {
		return 1;
	}
	if (str_2.find_c(&str_2, "3", 1) != 3) {
		return 1;
	}

	return 0;
}

int Test11()
{
	{ // String.insert_c tests
		INIT()

		str1.insert_c(&str1, 0, NULL);
		str1.insert_c(&str1, 5, NULL);
		str1.insert_c(&str1, 42, NULL);
		str1.insert_c(&str1, 42, "This string is out of bounds");
		str1.insert_c(&str1, 0, "I said: ");
		str1.insert_c(&str1, 21, " Good bye!");
		str1.insert_c(&str1, 14, " fucking");
		str2.insert_c(&str2, 0, NULL);
		str2.insert_c(&str2, 1, NULL);
		str2.insert_c(&str2, 1, "Out of bounds");
		str2.insert_c(&str2, 0, "Hello, world!");
		str3.insert_c(&str3, 0, NULL);
		str3.insert_c(&str3, 21, NULL);
		str3.insert_c(&str3, 0, "Hello, world!");

		if (strcmp(str1.str, "I said: Hello, fucking world! Good bye!This string is out of bounds") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "Hello, world!Out of bounds") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello, world!") != 0) {
			return 1;
		}

		DESTROY()
	}

	{ // String.insert_s tests
		INIT()

		String tests[7];

		StringInit(&(tests[0]), "This string is out of bounds");
		StringInit(&(tests[1]), "I said: ");
		StringInit(&(tests[2]), " Good bye!");
		StringInit(&(tests[3]), " fucking");
		StringInit(&(tests[4]), "Out of bounds");
		StringInit(&(tests[5]), "Hello, world!");
		StringInit(&(tests[6]), NULL);

		str1.insert_s(&str1, 0, &(tests[6]));
		str1.insert_s(&str1, 5, &(tests[6]));
		str1.insert_s(&str1, 42, &(tests[6]));
		str1.insert_s(&str1, 42, &(tests[0]));
		str1.insert_s(&str1, 0, &(tests[1]));
		str1.insert_s(&str1, 21, &(tests[2]));
		str1.insert_s(&str1, 14, &(tests[3]));
		str2.insert_s(&str2, 0, &(tests[6]));
		str2.insert_s(&str2, 1, &(tests[6]));
		str2.insert_s(&str2, 1, &(tests[4]));
		str2.insert_s(&str2, 0, &(tests[5]));
		str3.insert_s(&str3, 0, &(tests[6]));
		str3.insert_s(&str3, 21, &(tests[6]));
		str3.insert_s(&str3, 0, &(tests[5]));

		// Should not segfault
		str1.insert_s(&str1, 0, NULL);
		str2.insert_s(&str2, 0, NULL);
		str3.insert_s(&str3, 0, NULL);

		if (strcmp(str1.str, "I said: Hello, fucking world! Good bye!This string is out of bounds") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "Hello, world!Out of bounds") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello, world!") != 0) {
			return 1;
		}

		DESTROY()
	}

	return 0;
}

int Test12()
{
	String str_1;
	String str_2;
	String str_3;
	String str_4;
	String str_5;
	String str_6;
	String str_7;

	StringInit(&str_1, "-112312");
	StringInit(&str_2, "0");
	StringInit(&str_3, "1933");
	StringInit(&str_4, "33lachancla");
	StringInit(&str_5, "pasdebol7");
	StringInit(&str_6, "");
	StringInit(&str_7, NULL);

	if (str_1.to_int(&str_1) != -112312) {
		return 1;
	}
	if (str_2.to_int(&str_2) !=  0) {
		return 1;
	}
	if (str_3.to_int(&str_3) != 1933) {
		return 1;
	}
	if (str_4.to_int(&str_4) != 33) {
		return 1;
	}
	if (str_5.to_int(&str_5) != 0) {
		return 1;
	}
	if (str_6.to_int(&str_6) != 0) {
		return 1;
	}
	if (str_7.to_int(&str_7) != 0) {
		return 1;
	}

	return 0;
}

int Test13()
{
	String str[5];
	char **temp1;
	String *temp2;

	StringInit(&(str[0]), "Heyyyyyy, Salut à tous les amis !");
	StringInit(&(str[1]), "Snooping as usual, I see?");
	StringInit(&(str[2]), "");
	StringInit(&(str[3]), "I'm very Hungry");
	StringInit(&(str[4]), NULL);

	// split_c
	temp1 = str[0].split_c(&str[0], ',');
	if (strcmp(temp1[0], "Heyyyyyy") != 0)
		return 1;
	if (strcmp(temp1[1], " Salut à tous les amis !") != 0)
		return 1;

	temp1 = str[1].split_c(&str[1], ' ');
	if (strcmp(temp1[0], "Snooping") != 0)
		return 1;
	if (strcmp(temp1[1], "as") != 0)
		return 1;
	if (strcmp(temp1[2], "usual,") != 0)
		return 1;
	if (strcmp(temp1[3], "I") != 0)
		return 1;
	if (strcmp(temp1[4], "see?") != 0)
		return 1;

	temp1 = str[2].split_c(&str[2], 'b');
	if (temp1 != NULL)
		return 1;

	temp1 = str[3].split_c(&str[3], 'b');
	if (strcmp(temp1[0], "I'm very Hungry") != 0)
		return 1;

	temp1 = str[4].split_c(&str[4], 'b');
	if (temp1 != NULL)
		return 1;

	// split_s
	temp2 = str[0].split_s(&str[0], ',');
	if (strcmp(temp2[0].str, "Heyyyyyy") != 0)
		return 1;
	if (strcmp(temp2[1].str, " Salut à tous les amis !") != 0)
		return 1;

	temp2 = str[1].split_s(&str[1], ' ');
	if (strcmp(temp2[0].str, "Snooping") != 0)
		return 1;
	if (strcmp(temp2[1].str, "as") != 0)
		return 1;
	if (strcmp(temp2[2].str, "usual,") != 0)
		return 1;
	if (strcmp(temp2[3].str, "I") != 0)
		return 1;
	if (strcmp(temp2[4].str, "see?") != 0)
		return 1;

	temp2 = str[2].split_s(&str[2], 'b');
	if (temp2 != NULL)
		return 1;

	temp2 = str[3].split_s(&str[3], 'b');
	if (strcmp(temp2[0].str, "I'm very Hungry") != 0)
		return 1;

	temp2 = str[4].split_s(&str[4], 'b');
	if (temp2 != NULL)
		return 1;

	return 0;
}

int Test14()
{
	// Pas possible de tester le printf
	return 0;
}

int Test15()
{
	{ // String.join_c tests
		INIT()

		char const *tab1[] = {
			"Coucou,",
			"tu",
			"veux",
			"voir",
			"ma",
			"bite",
			"?",
			NULL
		};

		char const *tab2[] = {
			NULL
		};

		char const *tab3[] = {
			"Hello!",
			NULL
		};

		str1.join_c(&str1, ' ', tab1);
		str2.join_c(&str2, '!', tab2);
		str3.join_c(&str3, ',', tab3);

		if (strcmp(str1.str, "Coucou, tu veux voir ma bite ?") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello!") != 0) {
			return 1;
		}

		// Should not segfault
		str1.join_c(&str1, ' ', NULL);

		DESTROY()
	}

	{ // String.join_s tests
		INIT()

		String tab1[8];
		String tab2[1];
		String tab3[2];

		StringInit(&(tab1[0]), "Coucou,");
		StringInit(&(tab1[1]), "tu");
		StringInit(&(tab1[2]), "veux");
		StringInit(&(tab1[3]), "voir");
		StringInit(&(tab1[4]), "ma");
		StringInit(&(tab1[5]), "bite");
		StringInit(&(tab1[6]), "?");
		StringInit(&(tab1[7]), "");

		StringInit(&(tab2[0]), "");

		StringInit(&(tab3[0]), "Hello!");
		StringInit(&(tab3[1]), "");

		str1.join_s(&str1, ' ', tab1);
		str2.join_s(&str2, '!', tab2);
		str3.join_s(&str3, ',', tab3);

		if (strcmp(str1.str, "Coucou, tu veux voir ma bite ?") != 0) {
			return 1;
		}
		if (strcmp(str2.str, "") != 0) {
			return 1;
		}
		if (strcmp(str3.str, "Hello!") != 0) {
			return 1;
		}

		// Should not segfault
		str1.join_s(&str1, ' ', tab1);

		DESTROY()
	}
	return 0;
}


int Test16()
{
	INIT()

	String str_1;
	StringInit(&str_1, "extract<3me<3senpai");

	String *str_1_extract = str_1.substr(&str_1, 9, 2);
	if (strcmp(str_1_extract->str, "me") != 0) {
		printf("[Test 16] EXPECTED me GOT %s\n", str_1_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_2_extract = str_1.substr(&str_1, -1, 2);
	if (strcmp(str_2_extract->str, "i") != 0) {
		printf("[Test 16] EXPECTED i GOT %s\n", str_2_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_3_extract = str_1.substr(&str_1, 0, 3);
	if (strcmp(str_3_extract->str, "ext") != 0) {
		printf("[Test 16] EXPECTED ext GOT %s\n", str_3_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_4_extract = str_1.substr(&str_1, -1, -2);
	if (strcmp(str_4_extract->str, "") != 0) {
		printf("[Test 16] EXPECTED '' GOT %s\n", str_4_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_5_extract = str_1.substr(&str_1, -8, 3);
	if (strcmp(str_5_extract->str, "<3s") != 0) {
		printf("[Test 16] EXPECTED <3s GOT %s\n", str_5_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_6_extract = str_1.substr(&str_1, -8, -3);
	if (strcmp(str_6_extract->str, "<3sen") != 0) {
		printf("[Test 16] EXPECTED <3sen GOT %s\n", str_6_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_7_extract = str_1.substr(&str_1, -30, -1);
	if (strcmp(str_7_extract->str, "extract<3me<3senpa") != 0) {
		printf("[Test 16] EXPECTED extract<3me<3senpa GOT %s\n", str_7_extract->str);
		return 1;
	}

	str_1.assign_c(&str_1, "extract<3me<3senpai");

	String *str_8_extract = str2.substr(&str2, 1, 1);
	if (strcmp(str_8_extract->str, "") != 0) {
		printf("[Test 16] EXPECTED '' GOT %s\n", str_8_extract->str);
		return 1;
	}

	DESTROY()
	return 0;
}

int main()
{
	srandom(time(NULL));

	TEST(Test00, 0);
	TEST(Test01, 1);
	TEST(Test02, 2);
	TEST(Test03, 3);
	TEST(Test04, 4);
	TEST(Test05, 5);
	TEST(Test06, 6);
	TEST(Test07, 7);
	TEST(Test08, 8);
	TEST(Test09, 9);
	TEST(Test10, 10);
	TEST(Test11, 11);
	TEST(Test12, 12);
	TEST(Test13, 13);
	TEST(Test14, 14);
	TEST(Test15, 15);
	TEST(Test16, 16);

	return tests_status;
}
