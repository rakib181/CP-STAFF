#set -e
#-> compile them if you change in any file
#g++ sol.cpp -o sol
#g++ generator.cpp -o generator
#g++ brute.cpp -o brute

#TO RUN THIS BASHSCRIPT YOU HAVE TO USE GITBASH, IF THE OPERATING SYSTEM IS WINDOWS.

for((i = 1; ; ++i)); do
    ./generator.exe $i > input_file
    ./sol.exe < input_file > myAnswer
    ./brute.exe < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
