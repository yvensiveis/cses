const formatSection = (original) => {
    const words = original.split('-').slice(1);

    for (let i = 0; i < words.length; ++i) {
        if (words[i] == '1') {
            words[i] = 'I';
        } else if (words[i] == '2') {
            words[i] = 'II';
        } else {
            words[i] = words[i][0].toUpperCase() + words[i].substring(1);
        }
    }

    const result = words.join(' ');
    return result;
};

module.exports = { formatSection };
