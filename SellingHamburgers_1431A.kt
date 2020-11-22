fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val ar = readLine()!!.split(" ").map{it.toLong()}
        val ans = ar.sortedDescending().withIndex().maxOf{(it.index + 1) * it.value}
        println(ans)
    }
}
