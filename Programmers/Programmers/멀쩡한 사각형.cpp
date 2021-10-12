using namespace std;

long long gcd(long long a, long long b) {

    long long c;
    while (b != 0) {

        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long a, b;
    long long n = gcd(w, h);
    a = (long long)w / n;
    b = (long long)h / n;
    answer = (long long)w * h - (n * ((a + b) - 1));

    return answer;
}