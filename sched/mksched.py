import sys
from pprint import pprint
import pandas as pd
from tabulate import tabulate

expected_cols = [
    'day',
    'nlecture',
    'week',
    'subgroup',
    # 'subject',
    'discipline',
    'lecture_kind',
    'lecturer',
    # 'chair',
    'department',
    # 'auditorium',
    'classroom',
]

wtletter = {
    "в": "upper",
    'н': "lower",
}

table = pd.read_html('source.html', flavor='html5lib', header=0)[0]

if len(table.columns) != len(expected_cols):
    print(
        'Warning: table structure might have been changed!',
        file=sys.stderr
    )

# set internal names instead of displayed oness
table.columns = expected_cols

weeks = table.groupby('week', sort=False)
weeks = dict( iter(weeks) )
assert len(weeks) == 2, 'new week type?'

serialized = {}

for wktp, w in weeks.items():
    # remove column we're grouping by
    w.drop(columns='week', inplace=True)

    # strip trailing (not leading) nans in column 'discipline'
    days = w.groupby('day')
    for k, ilist in days.groups.items():
        for i in reversed(ilist):
            if w.loc[i].notna()['discipline']:
                break
            w.drop(index=i, inplace=True)

    # don't display some columns
    w.drop(columns=['lecturer', 'department'], inplace=True)

    # don't display NaNs
    w['subgroup'] = w['subgroup'].astype('Int8').astype('str').replace('<NA>', '')
    w.replace(pd.NA, '', inplace=True)

    # print(w)

    s_week = {}
    days = w.groupby('day', sort=False)
    for k, v in days:
    # remove column we're grouping by
        v.drop(columns='day', inplace=True)

        # s_week[k] = v.to_dict('index')
        s_week[k] = v.to_dict('records')

    wktp = wtletter[wktp]
    serialized[wktp] = s_week

# pprint(serialized)

headermap = dict(
    nlecture='№',
    subgroup='п/гр',
    discipline='предмет',
    lecture_kind='тип занятия',
    lecturer='преподаватель',
    department='кафедра',
    classroom='аудитория',
)

wkdisplay = dict(
    upper='верхняя неделя',
    lower='нижняя неделя',
)

invert = dict(
    lower='upper',
    upper='lower',
)

for wktp, wk in serialized.items():
    with open(wktp + '.md', 'w', encoding='utf-8') as f:
        print(wkdisplay[wktp].capitalize(), file=f)
        print('===', file=f)
        print(file=f)

        inverted = invert[wktp] + '.md'

        print(
            f'[Другая неделя]({inverted})',
            file=f
        )

        print(file=f)
        for dayname, day in wk.items():
            print(dayname, file=f)
            print('---', file=f)
            print(file=f)

            day = day.copy()
            # del day['lecturer']
            # del day['department']

            t = tabulate(day, tablefmt='github', headers=headermap)

            print(t, file=f)
            print(file=f)
