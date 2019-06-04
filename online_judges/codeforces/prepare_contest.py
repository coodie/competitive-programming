import argparse
import os
import shutil

TEMPLATES_DIR = "./templates"
TEMPLATE_FILENAME = "template"
PROBLEM_NAMES = ["A", "B", "C", "D", "E", "F"]


def get_contest_template(lang):
    path = ''.join([TEMPLATES_DIR, "/", TEMPLATE_FILENAME, ".", lang])
    with open(path, 'r') as f:
        s = f.read()
    return s


def create_directory(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print('Error: Creating directory. ' + directory)


def generate_directory(dir_name, lang):
    template = get_contest_template(lang)
    create_directory(dir_name)
    for problem in PROBLEM_NAMES:
        path = ''.join([dir_name, "/", problem, ".", lang])
        with open(path, 'w') as f:
            f.write(template)

    path = ''.join([dir_name, "/", "in.txt"])
    with open(path, 'x') as f:
        pass

    if lang == 'cpp':
        makefile_path = ''.join([TEMPLATES_DIR, "/", "Makefile"])
        shutil.copyfile(makefile_path, dir_name + "/Makefile")


def main():
    parser = argparse.ArgumentParser(description='Generate contest template.')
    parser.add_argument('contest_num')
    parser.add_argument('lang', nargs='?', choices=['cpp'], default='cpp')
    parser.add_argument('div', nargs='?', choices=['1', '2', '3'],
                        metavar='div', default='2')
    args = parser.parse_args()
    dir_name = ''.join([args.contest_num, '_div', args.div])
    generate_directory(dir_name, args.lang)


main()
