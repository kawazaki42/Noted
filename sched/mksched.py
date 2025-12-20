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

# print(len(expected_cols))

table = pd.read_html('source.html', flavor='html5lib', header=0)[0]

# print(table.columns.to_list())

# colcount = len(table.columns)

if len(table.columns) != len(expected_cols):
    print(
        'Warning: table structure might have been changed!',
        file=sys.stderr
    )

table.columns = expected_cols

# assert len(expected_cols)

# table.sort_values('week', inplace=True)

# table.set_index( ['day', 'nlecture', 'week', 'subgroup'], inplace=True )

# table = table.reorder_levels(['week', 'day', 'nlecture', 'subgroup'])

# print(table)

# raise SystemExit

# table.reorder_levels([''])

weeks = table.groupby('week', sort=False)
weeks = dict( iter(weeks) )
assert len(weeks) == 2, 'new week type?'

# print(weeks)

# u, l = weeks['в'], weeks['н']

serialized = {}

# with open('out.md', 'w', encoding='utf-8') as f:
# for w in (u, l):
for wktp, w in weeks.items():
    w.drop(columns='week', inplace=True)

    # print(g)

    # strip trailing (not leading) nans in column 'discipline'
    days = w.groupby('day')
    # g = w.groupby('day').groups
    for k, ilist in days.groups.items():
        # print(ilist)
        for i in reversed(ilist):
            if w.loc[i].notna()['discipline']:
                break
            # print(f'dropped {i}')
            w.drop(index=i, inplace=True)
    # w.dropna(subset='discipline', inplace=True)
    # mask = w[['discipline']].notna().any()[::-1].cummax()[::-1]
    # w['discipline'] = w['discipline'][mask]
    # w.set_index( ['day', 'nlecture', 'subgroup'], inplace=True )
    # mask = w['discipline'][::-1].notna().cummax()[::-1]
    # w = w[]
    # w.dtypes['subgroup'] = 'int'
    w.drop(columns=['lecturer', 'department'], inplace=True)
    w['subgroup'] = w['subgroup'].astype('Int8').astype('str').replace('<NA>', '')
    w.replace(pd.NA, '', inplace=True)
    print(w)
    # w.to_markdown('out.md')
    s_week = {}
    days = w.groupby('day', sort=False)
    for k, v in days:
        print(k)
        v.drop(columns='day', inplace=True)
        # v.set_index(['nlecture', 'subgroup'], inplace=True)
        # s_week[k] = v.to_dict('index')
        s_week[k] = v.to_dict('records')

    wktp = wtletter[wktp]
    serialized[wktp] = s_week
        # html = v.to_html(index=False, na_rep='')
        # html = v.to_html(na_rep='')
        # print(f'\n{k}\n---\n', file=f)
        # print(html, file=f)
    # print(list(w.iloc))
    # print(list(w['discipline']))
    # print(w.loc['понедельник'])

    # # w = w.set_index('day')
    # new_days = {}
    # for k, v in days:
    #     i = v['discipline'].last_valid_index()
    #     print(i)
    #     new_days[k] = v.drop(columns='day')
    #     # print(k, '===', v)
    #     # w.loc[k] = v
    #     # print(v.columns)
    #     # print(w.loc[k].columns)

    # # w = pd.DataFrame(new_days)
    # w = pd.concat(new_days)
    # print(w)

    # mask = df.notna().any(axis=1)
    # last_valid = mask[mask].index[-1] if mask.any() else None

    # if last_valid is not None:

# print(table.groupby("День недели"))

# dir(table.columns[0:2])

# m = list(table.groupby(table.columns[2]))
# m = table.groupby(table.columns[2])
# m = dict( m )

# for _, table in m.items():
# for _, table in m:

#     table = table.set_index(table.columns[0:2].to_list())

#     # table = table.set_index(table.columns[0:4].to_list())

#     # table.to_html("test.html")

#     # print( list(table) )

#     # print(table)

#     # table.to_json("out.json", orient='records')

#     j = table.to_json(orient='table')
#     import json, pprint
#     data = json.loads(j)
#     pprint.pprint(data)

#     # print(list(data))

#     # print(table.loc["понедельник"])

#     # print(type(table.iloc[0]))

#     # print(t)

#     # print( type(table.columns[0]) )

#     # print(table)

pprint(serialized)

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
    lower='верхняя неделя',
    upper='нижняя неделя',
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
            #     '№',
            #     'п/гр',
            #     'предмет',
            #     'тип занятия',
            #     'преподаватель',
            #     'кафедра',
            #     'аудитория',
            # ])

            print(t, file=f)
            print(file=f)
