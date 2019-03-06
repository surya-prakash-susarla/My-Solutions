#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int llint;

//  Range :  pair<llint,llint> : pair.first = higher limit ; pair.second = lower limit

llint people_before(llint value, vector<pair<llint, llint>> ranges)
{
    llint k = 0;
    for (llint i = 0; i < ranges.size(); i++)
    {
        if (ranges[i].first > value)
            k += ranges[i].first - value;
        if (ranges[i].second > value)
            k -= ranges[i].second - value - 1;
    }
    return k;
}

llint getLower(llint value, vector<pair<llint, llint>> ranges)
{
    llint return_value = -1;
    for (pair<llint, llint> it : ranges)
        if (it.second < value)
            if (it.first >= value)
                return value - 1;
            else if (return_value == -1 or it.first > return_value)
                return_value = it.first;
    return return_value;
}

llint getHigher(llint value, vector<pair<llint, llint>> ranges)
{
    llint return_value = -1;
    for (pair<llint, llint> it : ranges)
        if (it.first > value)
            if (it.second <= value)
                return value + 1;
            else if (return_value == -1 or it.second < return_value)
                return_value = it.second;
    return return_value;
}

llint calc(llint location, vector<pair<llint, llint>> ranges, llint total_students)
{
    if (location > total_students)
        return 0;
    llint max_upper_value = ranges[0].first, max_lower_value = ranges[ranges.size() - 1].second;
    llint answer = -1, check_value = (max_upper_value + max_lower_value) / 2, prev_location = -1, prev_answer = -1;
    while (answer != location)
    {
        if (check_value < 0)
            return prev_location;
        answer = people_before(check_value, ranges) + 1;
        if (answer < location)
        {
            prev_location = check_value;
            prev_answer = answer;
            check_value = getLower(check_value, ranges);
        }
        else if (answer > location)
        {
            if (prev_answer != -1 and prev_answer < location)
                return prev_location;
            check_value = getHigher(check_value, ranges);
        }
    }
    return check_value;
}

bool sortRanges(const pair<llint, llint> &a, const pair<llint, llint> &b)
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first and a.second > b.second)
        return true;
    return false;
}

int main()
{
    llint t;
    cin >> t;
    for (llint k = 1; k <= t; k++)
    {
        llint n, q;
        cin >> n >> q;
        llint x1, x2, y1, y2, z1, z2, a1, a2, a3, b1, b2, b3, c1, c2, c3, m1, m2, m3;
        cin >> x1 >> x2 >> a1 >> b1 >> c1 >> m1 >> y1 >> y2 >> a2 >> b2 >> c2 >> m2 >> z1 >> z2 >> a3 >> b3 >> c3 >> m3;
        vector<llint> x_values, y_values, z_values;
        x_values.push_back(x1);
        x_values.push_back(x2);
        y_values.push_back(y1);
        y_values.push_back(y2);
        z_values.push_back(z1);
        z_values.push_back(z2);
        for (llint i = 2; i < n; i++)
        {
            x_values.push_back((a1 * x_values[i - 1] + b1 * x_values[i - 2] + c1) % m1);
            y_values.push_back((a2 * y_values[i - 1] + b2 * y_values[i - 2] + c2) % m2);
        }
        vector<pair<llint, llint>> ranges;
        llint total_students = 0;
        for (llint i = 0; i < n; i++)
        {
            ranges.push_back(make_pair((max(x_values[i], y_values[i]) + 1), (min(x_values[i], y_values[i]) + 1)));
            total_students += ranges[i].first - ranges[i].second + 1;
        }
        sort(ranges.begin(), ranges.end(), sortRanges);
        llint answer = 0;
        answer += 1 * calc(z_values[0] + 1, ranges, total_students);
        if (q > 1)
            answer += 2 * calc(z_values[1] + 1, ranges, total_students);
        for (llint i = 2; i < q; i++)
        {
            z_values.push_back((a3 * z_values[i - 1] + b3 * z_values[i - 2] + c3) % m3);
            answer += (i + 1) * calc(z_values[i] + 1, ranges, total_students);
        }
        cout << "Case #" << k << ": " << answer << endl;
    }
    return 0;
}