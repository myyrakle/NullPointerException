#include <cstdio>
#include <cstring>

char v[5][6];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline bool isExist(char *word, int len, int x, int y)
{
    if (len < 0) return true;
    
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < 5 &&
            ny >= 0 && ny < 5 &&
            v[nx][ny] == word[len] &&
            isExist(word, len-1, nx, ny)) return true;
    }
    
    return false;
}
int main()
{
    int c;
    scanf("%d", &c);
    
    char word[11];
    while (c--)
    {
        for (int i = 0; i < 5; ++i) scanf(" %s", v[i]);
        
        int n;
        scanf("%d", &n);
        
        while (n--)
        {
            scanf(" %s", word);
            printf("%s ", word);
            
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    if (v[i][j] == word[strlen(word)-1] && isExist(word, strlen(word)-2, i, j))
                        goto FLG;
            
            puts("NO");
            continue;
            
            FLG:
            puts("YES");
        }
    }
    
    return 0;
}
