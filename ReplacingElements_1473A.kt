/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

fun main() {
    var t = readLine()!!.toInt()
    for (r in 0 until t) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val ar = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        ar.sort()
        var bad = false
        ar.forEach {
            if (it > k) {
                bad = true
            }
        }
        println(if (ar[0] + ar.get(1) <= k || !bad) "YES" else "NO")
    }
}
