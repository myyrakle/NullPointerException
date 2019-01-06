#include <iostream>
#include <vector>
#include <limits.h>

int main()
{
    int Case;

    std::cin>>Case;

    for(int i=0; i<Case; i++)
    {
        int max_len;
        int min_len;
        std::cin>>max_len>>min_len;

        std::vector<int> values;
        values.reserve(max_len);
        int temp;
        for(int i=0; i<max_len; i++)
            std::cin>>temp, values.push_back(temp); 

        double min_average = 200.0;
        for(int len = min_len; len<=max_len; len++)
        {
            for(int i=0; i+(len-1)<max_len; i++)
            {
                int sum=0;
                for(int j=i; j<(i+len); j++)
                    sum+=values[j];
                double result = (double)sum / (double)len;

                if(min_average>result)
                    min_average=result;
            }
        }

        printf("%.12f\n",min_average);
    }
}
 
