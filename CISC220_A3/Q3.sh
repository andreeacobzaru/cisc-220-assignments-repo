letter2gp() {
    case $1 in
        "A+") echo '4.3' ;;
        "A") echo '4.0' ;;
        "A-") echo '3.7' ;;
        "B+") echo '3.3' ;;
        "B") echo '3.0' ;;
        "B-") echo '2.7' ;;
        "C+") echo '2.3' ;;
        "C") echo '2.0' ;;
        "C-") echo '1.7' ;;
        "D+") echo '1.3' ;;
        "D") echo '1.0' ;;
        "D-") echo '0.7' ;;
        "F") echo '0.0' ;;
        *)   echo '-1' ;;
    esac
}