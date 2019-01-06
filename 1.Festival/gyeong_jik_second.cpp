#include <iostream>
#include <vector>

auto main() -> decltype(int{44})
{
    int Case;

    scanf("%d ", &Case);

    for(int i=0; i<Case; i++)
    {
        std::vector<int> sums;
        int max_len;
        int min_len;
        scanf("%d %d ", &max_len, &min_len);

        sums.reserve(max_len);
        
        int temp;
        scanf("%d ", &temp);
        sums.push_back(temp);
        for(int i=1; i<max_len; i++)
        {
            scanf("%d ", &temp);
            sums.push_back(sums[i-1]+temp);
        }

        double min_average = 200.0;
        for(int len = min_len; len<=max_len; len++)
        {
            for(int i=0; i+(len-1)<max_len; i++)
            {
                auto before = i==0 ? 0 : sums[i-1];
                auto result = (sums[i+len-1]-before) 
                / static_cast<double>(len);

                if(min_average>result)
                    min_average=result;
            }
        }

        printf("%.12f\n",min_average);
    }
}
