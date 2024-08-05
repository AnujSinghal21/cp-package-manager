(async () => {

    const current_url = window.location.href;
    if (current_url.startsWith('https://codeforces.com/problemset') 
        || current_url.startsWith('https://codeforces.com/contest/')) {
            if (current_url.includes('submit')) {
                const code = await navigator.clipboard.readText();
                if (code === "") {
                    console.log("No code found in clipboard");
                    return 0;
                }
                const lines = code.split('\n');
                if (!(lines.length >= 1 && lines[0].startsWith('// Question: '))) {
                    return 0;
                }
                const firstLine = lines[0];
                const parts = firstLine.split('/');
                if (parts.length < 2) {
                    console.log("Invalid question format");
                    return 0;
                }
                const codeElement = document.querySelector('textarea[name="source"]');
                if (codeElement === null) {
                    console.log("Code element not found");
                    return 0;
                }
                codeElement.value = code;

                if (current_url.startsWith('https://codeforces.com/contest/')) {
                    let question = parts[parts.length - 1];
                    if (question[question.length - 1] === '\r') {
                        question = question.substring(0, question.length - 1);
                    }
                    const questionElement = document.querySelector('select[name="submittedProblemIndex"]');
                    if (questionElement === null) {
                        console.log("Question element not found");
                        return 0;
                    }
                    questionElement.value = question;
                    questionElement.blur();
                    const submitButton = document.querySelector('input[id="singlePageSubmitButton"]');
                    if (submitButton === null) {
                        console.log("Submit button not found");
                        return 0;
                    }
                    const errorElements = document.querySelectorAll('.error');
                    for (let i = 0; i < errorElements.length; i++) {
                        if (errorElements[i].textContent.length > 2) {
                            return 0;
                        }
                    }
                    const startTime = Date.now();
                    const interval = 100;
                    const timeout = 5000;
                    const checkButton = setInterval(() => {
                        if (!submitButton.disabled) {
                            clearInterval(checkButton); // Stop polling
                            submitButton.click();
                        } else if (Date.now() - startTime > timeout) {
                            // Timeout reached
                            console.log('Timeout: submitButton did not become enabled');
                            clearInterval(checkButton); // Stop polling
                        }
                    }, interval);

                }else{
                    const question = parts[parts.length - 2] + parts[parts.length - 1];
                    const questionElement = document.querySelector('input[name="submittedProblemCode"]');  
                    if (questionElement === null) {
                        console.log("Question element not found");
                        return 0;
                    }
                    questionElement.value = question;
                    const submitButton = document.querySelector('input[id="singlePageSubmitButton"]');
                    if (submitButton === null) {
                        console.log("Submit button not found");
                        return 0;
                    }
                    const errorElements = document.querySelectorAll('.error');
                    for (let i = 0; i < errorElements.length; i++) {
                        if (errorElements[i].textContent.length > 2) {
                            return 0;
                        }
                    }
                    const startTime = Date.now();
                    const interval = 100;
                    const timeout = 5000;
                    const checkButton = setInterval(() => {
                        if (!submitButton.disabled) {
                            clearInterval(checkButton); // Stop polling
                            submitButton.click();
                        } else if (Date.now() - startTime > timeout) {
                            // Timeout reached
                            console.log('Timeout: submitButton did not become enabled');
                            clearInterval(checkButton); // Stop polling
                        }
                    }, interval);
                }
                return 0;
            }
            const testcases = [];
            const inputs = [];
            document.querySelectorAll('.sample-test .input pre').forEach(inputElement => {
                let input = "";
                inputElement.querySelectorAll('div').forEach(div => {
                    input += div.textContent + "\n";
                });
                inputs.push(input);
              });
            const outputs = []; 
            document.querySelectorAll('.sample-test .output pre').forEach(outputElement => {
                const output = outputElement.textContent;
                outputs.push(output);
              });
            if (inputs.length !== outputs.length) {
                console.log("Number of inputs and outputs are not equal");
                return 0;
            }
            for (let i = 0; i < inputs.length; i++) {
                testcases.push({
                    input: inputs[i],
                    output: outputs[i]
                });
            }
            if (testcases.length === 0) {
                console.log("No testcases found");
                return 0;
            }

            const request = {
                testcases: testcases,
                url: current_url,
            };
            
            const apiUrl = "http://127.0.0.1:5000/cf-parser/testcases/";
            fetch(apiUrl, {
                method: "POST",
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify(request)
            }).then(response => response.json())
            .then(data => console.log('Success:', data))
            .catch((error) => console.error('Error:', error));
        }
    return 0;
  })();
  