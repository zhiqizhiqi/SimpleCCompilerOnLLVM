typedef struct _attr
{
	int space;
	int isLeft;
	char* type;
} Attr;

typedef struct _node {
	char* content;
	char* token;
	Attr attr;
	struct _node *next;
	struct _node *child;
} Node;
