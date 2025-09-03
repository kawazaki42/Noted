const dofw = ['понедельник' 'вторник' 'среда' 'четверг' 'пятница' 'суббота' 'воскресенье']

export def main [week: string] {
    1..6
    |each {
        let i = $in

        let table = (
            open $"($week)/($i).csv"
            | table --theme markdown --index=false
        )

        let dayname = $dofw |get ($i - 1)
        $"($dayname)\n---\n($table)\n"
    }
    | str join
    | ansi strip
    | str replace --all --regex --multiline '^([|]-+[|]-*)-\|' '${1}:|'
}

export def upper [] {
    "ВЕРХНЯЯ неделя\n===\n\n" ++ (main upper) |save -f upper/readme.md
}

export def lower [] {
    "НИЖНЯЯ неделя\n===\n\n" ++ (main lower) |save -f readme/lower.md
}