# Objetos

Object Destructuring

Entre chaves `{}` podemos filtrar apenas os dados que nos interessam em um objeto. 

```javascript
const user = {
    id: 42,
    displayName: 'jdoe',
    fullname:{
        firstName: 'John'
        lastName: 'Doe'
    }
};

function userIf({id}){
    return id;
}

function getFullName({fullName: {firstName: first, lastName: last}}){
    return `${first} ${last}`; // É onde acontece o objetct destructuring
}

userId(user)

//42

getFullName(user)

// John Doe 
```

Perceba que na função `getFullName`, podemos criar uma espécie de equivalência das chaves `{firstName}` com um outro nome que podemos criar. Como por exemplo `{first}`. E o mesmo acontece com o `{lastName}` e o `{last}`.




