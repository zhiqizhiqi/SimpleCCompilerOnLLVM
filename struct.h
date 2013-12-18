typedef struct _attr
{
	int space;
	int isLeft;
} Attr;

typedef struct _node {
	char* content;
	char* token;
	Attr attr;
	struct _node *next;
	struct _node *child;
} Node;
