/**
 * @template T
 * @param {function():T} producer
 * @return {function():symbol|T}
 */
export function lazy<T>(producer: () => T): () => symbol | T;
