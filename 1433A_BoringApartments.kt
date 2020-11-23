/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

fun main() {
    val testcases = readLine()!!.toInt()
    for (test in 0 until testcases) {
        val num = readLine()!!.toInt()
        val digit = num % 10
        var ans = (digit - 1) * 10
        for (i in 1 .. num.toString().length) ans += i
        println(ans)
    }
}
