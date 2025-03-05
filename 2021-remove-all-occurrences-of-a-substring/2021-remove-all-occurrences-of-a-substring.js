/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
var removeOccurrences = function(s, part) {
    
    const rec = (s) => {
        if (!s.includes(part)) return s;
        return rec(s.replace(part, ""));
    }

    return rec(s);
};