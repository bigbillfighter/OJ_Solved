#include <bits/stdc++.h>
using namespace std;

struct Point {
 	int x;
 	int y;
 	Point(int xx, int yy) : x(xx), y(yy) {}
    Point(){}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 获取最大收益理财产品组合
     * @param products Point类vector 理财产品数据列表
     * @param months int整型 总投入月份
     * @return Point类vector
     */
    void find_max(vector<Point>& products, int months, int pre_sum, int& max_val, vector<Point>& ans_queue, vector<Point>& crt_queue){
        Point crt_point;

        for(int i=0; i<products.size(); i++){

            if(products[i].x <= months){
                crt_point = Point(products[i].x, products[i].y);
                crt_queue.push_back(crt_point);
                find_max(products, months-products[i].x, pre_sum + products[i].y, max_val, ans_queue, crt_queue);

                if(pre_sum + products[i].y > max_val){
                    ans_queue.clear();
                    for(int j=0; j<crt_queue.size(); j++){
                        crt_point = Point(crt_queue[j].x, crt_queue[j].y);
                        ans_queue.push_back(crt_point);
                    }
                    max_val = pre_sum + products[i].y;
                    // cout << max_val << endl;
                    // for(int j=0; i<crt_point.size(); j++){
                    //     cout << "crt x: " << crt_point[j].x << ", y: " << crt_point[j].y << endl;
                    // }
                }

                crt_queue.pop_back();
            }
        }
    }    

    vector<Point> maxIncomeProducts(vector<Point>& products, int months) {
        // write code here
        int max_val = 0;
        vector<Point> ans_queue, crt_queue;
        find_max(products, months, 0, max_val, ans_queue, crt_queue);
        return ans_queue;
    }   
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    Solution solu;

    int n;
    int x, y;
    cin >> n;
    int months;
    cin >> months;

    vector<Point> input_points;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        Point crt_point = Point(x, y);
        input_points.push_back(crt_point);
    }
    vector<Point> rst = solu.maxIncomeProducts(input_points, months);
    for(int i=0; i<rst.size(); i++){
        cout << "x: " << rst[i].x << ", y: " << rst[i].y << endl;
    }

    return 0;
}