const path = require('path');
const fs = require('fs');

const format = require('./format')

let output_text = '';

const head_file = path.join('.', 'base', 'head.tex');
const tail_file = path.join('.', 'base', 'tail.tex');

const output_file = path.join('.', 'output', 'main.tex');

const head_text = fs.readFileSync(head_file, 'utf8');
const tail_text = fs.readFileSync(tail_file, 'utf8');

output_text += head_text + '\n';

const root_path = path.join(__dirname, '..');

const root_children = fs.readdirSync(root_path);
const sections = root_children.filter((child) => '01'.includes(child[0]));

sections.forEach((section) => {
    output_text += `\\section{${format.formatSection(section)}}\n`;

    const section_path = path.join(root_path, section);
    const problems = fs.readdirSync(section_path);

    problems.forEach((problem) => {
        output_text += `\\subsection{${format.formatSection(problem)}}\n`;

        const problem_path = path.join(section_path, problem);
        problem_children = fs.readdirSync(problem_path);
        const solutions = problem_children.filter((child) => child != 'README.md');

        solutions.forEach((solution) => {
            output_text += `\\subsubsection{${solution}}\n`;

            const solution_path = path.join(problem_path, solution);
            const solution_text = fs.readFileSync(solution_path, 'utf8');
            
            output_text += '\\begin{lstlisting}[language=C++, numbers=none]\n';

            output_text += solution_text + '\n';

            output_text += '\\end{lstlisting}\n\n';
        });
    });
});

output_text += tail_text + '\n';

fs.writeFileSync(output_file, output_text, { encoding: 'utf8' });
