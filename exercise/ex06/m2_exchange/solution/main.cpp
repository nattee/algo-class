#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int k;
	scanf("%d", &k);
	for (int tk = 0; tk < k; ++tk)
	{
    	int n;
    	scanf("%d", &n);
    
    	float* g = new float[n * n];
    	float* d = new float[n * n];
    	float* td = new float[n * n];
#define MG(j, i) g[(j) * n + (i)]
#define MD(j, i) d[(j) * n + (i)]
#define MTD(j, i) td[(j) * n + (i)]
    
    	for (int j = 0; j < n; ++j)
    		for (int i = 0; i < n; ++i)
    			scanf("%f", &MG(j, i));
    
    	memcpy(d, g, sizeof(float) * n * n);
    
    	bool isStop = false;
    	for (int a = 0; a < n; ++a)
    	{
    		for (int i = 0; i < n; ++i)
    		{
    			for (int j = 0; j < n; ++j)
    			{
    				float z = MD(i, a) * MD(a, j);
    				if (z > MD(i, j))
    				{
    					MTD(i, j) = z;
    					if (i == j && z > 1)
    					{
    						isStop = true;
    						break;
    					}
    				}
    				else MTD(i, j) = MD(i, j);
    			}
    			if (isStop) break;
    		}
    		if (isStop) break;
    		float* t = d;
    		d = td;
    		td = t;
    		//for (int j = 0; j < n; ++j)
    		//{
    		//	for (int i = 0; i < n; ++i)
    		//		printf("%f\t", MD(j, i));
    		//	printf("\n");
    		//}
    		//printf("\n");
    	}
    	
    	if (isStop) 
    		printf("YES\n");
    	else printf("NO\n");
    	delete[] g;
    	delete[] d;
    	delete[] td;
#undef MG
#undef MD
#undef MTD
	}

    //system("PAUSE");
}
