/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

fun main(args: Array<String>) {
	val test = (readLine()!!).toInt()
	for (x in 0 until test){
		val (a, b) = readLine()!!.split(' ').map { it.toInt() }
		println(a + b)
	}
}
