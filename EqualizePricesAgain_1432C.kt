/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
 */

import java.lang.Math.ceil
import java.util.Scanner

fun main() {
    val sc = Scanner(System.`in`)
    val test = sc.nextInt()
    sc.nextLine()
    for (u in test downTo 1 step 1) {
        val nums = sc.nextDouble()
        sc.nextLine()
        var sum: Double = 0.0
        for (i in 1..nums.toInt()) {
            sum += sc.nextDouble()
        }
        println(ceil(sum/nums).toInt())
    }

}
