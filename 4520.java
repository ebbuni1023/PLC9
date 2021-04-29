public static List<Integer> solveGame(int N){
	List<Integer> moves = new LinkedList<>();
	return solveGameHelper(N, moves);
}
private static List<Integer> solveGameHelper(int N, List<Integer> moves){
	if(N == 0){
		return moves;
	} else if(N < 4) {
		moves.add(N);
		return moves;
	}
	for (int numOfSticks = 1; numOfSticks <= 3; numOfSticks++) {
		moves.add(numOfSticks);
		if(solveGame(N-numOfSticks).size() == 0) {
			return solveGameHelper(N - numOfSticks - 1, moves);
		}
		moves.remove(moves.size()-1);	
	}
	return moves;
}
