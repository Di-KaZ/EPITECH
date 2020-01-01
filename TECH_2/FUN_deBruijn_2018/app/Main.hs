module Main where
import System.Environment
import System.Exit
import Lib

main :: IO ()
main = do
	argstr <- getArgs
	let args = getParameters argstr
	if flag args == "-h"
		then displayHelp
	else if flag args == "--check"
		then do
			str <- getLine
			putStrLn(checkIfDeBruijin args str)
	else if flag args == "--unique"
		then do
			str1 <- getLine
			str2 <- getLine
			putStrLn (checkIfUnique args str1 str2)
	else if flag args == "--clean"
		then do
			str2 <- getAllValidDeBruijin args
			putStrLn str2
	else exitWith (ExitFailure 84)
