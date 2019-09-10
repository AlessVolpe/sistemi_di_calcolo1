rm -f file2.dat
gcc e2_main.c e2.c -o e2
./e2 file1.dat file2.dat
diff file1.dat file2.dat
res=$?
if [ $res -eq 0 ]; then
    echo "Risultato: 1/1"
else    
    echo "Risultato: 0/1"
fi
