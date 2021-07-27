using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
            Dictionary<string, int> hash = new Dictionary<string, int>();
            int answer = 1;
            // Generic에 경우 Dictionary -> Generic 미사용시 Hashtable

            for(int i = 0; i < clothes.GetLength(0); i++) //GetLength(0)로 첫배열의 크기를 나타냄.
            {
                if (!hash.ContainsKey(clothes[i, 1])) hash.Add(clothes[i, 1], 1);
                // 만약 키값이 존재하지 않는다면 <key,1> 형식으로 데이터 기입
                else hash[clothes[i, 1]]++;// 만약 키값이 존재한다면 value값 1추가
            }

            foreach(KeyValuePair<string,int> item in hash)
            {
                answer *= item.Value+1;
                // 이 문제 KEY POINT
                // headgear 2개 eyewear 1개일 경우
                // headgear 0 -> eyewear 1
                // headgear 1 -> eyewear 0, eyewear 1
                // headgear 2 -> eyewear 0, eyewear 1
                // 형식으로 경우의 수를 구할 수 있음.
                // 즉 clothes의 types의 개수들의 경우의 수를 모두 구하는 것인데,
                // 0개 까지 포함하여 각 types마다 1을 더해 곱하면 모든 경우의 수가 나온다.
                // 이때 다 안입는 경우도 포함되므로 마지막에 모든 경우의 수 중 하나도 입지 않은
                // 경우의수 1개를 빼면 값이 나온다.
            }
            return answer-1;
    }
}
