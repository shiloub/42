import { useState } from "react";

function Square({ value , onSquareClick }) {
  return (
    <
      button className="square" onClick={onSquareClick}
    >
      {value}
    </button>
  );
}

export default function Game() {
  const [history, setHistory] = useState([Array(9).fill(null)]);
  const [currentMove, setCurrentMove] = useState(0);
  const xIsNext = currentMove % 2 === 0;
  const currentSquares = history[currentMove];

  function handlePlay(nextMove) {
    const nextHistory = [...history.slice(0, currentMove + 1), nextMove];
    setHistory(nextHistory);
    setCurrentMove(nextHistory.length - 1);
    console.log("current move =" + currentMove);
  }
  function jumpTo(nextmove) {
    setCurrentMove(nextmove);
    console.log(xIsNext);
  }

  const moves = history.map((squares, move) =>{
    let descrip = "go to move #" + (move + 1);
    if (move == history.length - 1)
    {
      return (
        <li key={move}> You are at move #{move + 1}</li>
      )

    }
    return (
    <li key={move}>
      <button onClick={ () => jumpTo(move)}>{descrip}</button>
    </li>
    )
  })
  return (
    <div className="game">
      <div className="game-board">
        <Board xIsNext={xIsNext} squares={currentSquares} onPlay={handlePlay}/>
      </div>
      <div className="game-info">
        <ol>{moves}</ol>
      </div>
    </div>
  );
}

function Board({squares, xIsNext, onPlay}) {
  function handleClick(i){
    if (squares[i] || calculateWinner(squares))
    return;
    const temp = squares.slice();
    xIsNext == true ? temp[i] = 'X' : temp[i] = 'O';
    onPlay(temp);
  };

  let winner=calculateWinner(squares);
  let status;
  if (winner == 'X')
    status = "player 1 wins";
  else if (winner == 'O')
  status = "player 2 wins";
  else if (winner == 'e')
  status = "game is over: you are even";
  else
    xIsNext == true ? status = "player 1 to play" : status = "player 2 to play";
  return (
    <>
    <div className="status">{status}
    {
      Array(3).fill(null).map((_, rowIndex) => (
        <div className="row" key={rowIndex}>
          {Array(3).fill(null).map((_, colIndex) => {
            const caseIndex = rowIndex * 3 + colIndex;
            return (
              <Square key={caseIndex}
              value={squares[caseIndex]}
              onSquareClick={() => handleClick(caseIndex)}/>
            )
          })}
        </div>
      ))
    }
    </div>
  </>
    );
}

function calculateWinner(squares) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
  ];
  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  for (let i = 0; i < squares.length; i++) {
    if (!squares[i])
      return null;
  }
  return ('e');
}